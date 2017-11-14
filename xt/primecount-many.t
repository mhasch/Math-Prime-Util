#!/usr/bin/env perl
use strict;
use warnings;

use Test::More;
use Math::Prime::Util qw/prime_count prime_count_lower prime_count_upper/;
use Digest::SHA qw/sha256_hex/;

my $use64 = ~0 > 4294967295;

my %pivals = (
                1000 =>                168,
               10000 =>               1229,
              100000 =>               9592,
             1000000 =>              78498,
            10000000 =>             664579,
           100000000 =>            5761455,
          1000000000 =>           50847534,
         10000000000 =>          455052511,
        100000000000 =>         4118054813,
       1000000000000 =>        37607912018,
       2000000000000 =>        73301896139,
       3000000000000 =>       108340298703,
       4000000000000 =>       142966208126,
       5000000000000 =>       177291661649,
       6000000000000 =>       211381427039,
       7000000000000 =>       245277688804,
       8000000000000 =>       279010070811,
       9000000000000 =>       312600354108,
      10000000000000 =>       346065536839,
      20000000000000 =>       675895909271,
      30000000000000 =>      1000121668853,
      40000000000000 =>      1320811971702,
      50000000000000 =>      1638923764567,
      60000000000000 =>      1955010428258,
      70000000000000 =>      2269432871304,
      80000000000000 =>      2582444113487,
      90000000000000 =>      2894232250783,
     100000000000000 =>      3204941750802,
     200000000000000 =>      6270424651315,
     300000000000000 =>      9287441600280,
     400000000000000 =>     12273824155491,
     500000000000000 =>     15237833654620,
     600000000000000 =>     18184255291570,
     700000000000000 =>     21116208911023,
     800000000000000 =>     24035890368161,
     900000000000000 =>     26944926466221,
    1000000000000000 =>     29844570422669,
   10000000000000000 =>    279238341033925,
   20000000000000000 =>    547863431950008,
   40000000000000000 =>   1075292778753150,
  100000000000000000 =>   2623557157654233,
 1000000000000000000 =>  24739954287740860,
 2000000000000000000 =>  48645161281738535,
 3000000000000000000 =>  72254704797687083,
 4000000000000000000 =>  95676260903887607,
 4185296581467695669 => 100000000000000000,
 5000000000000000000 => 118959989688273472,
 6000000000000000000 => 142135049412622144,
 7000000000000000000 => 165220513980969424,
 8000000000000000000 => 188229829247429504,
 9000000000000000000 => 211172979243258278,
10000000000000000000 => 234057667276344607,
              524288 =>              43390,
             1048576 =>              82025,
             2097152 =>             155611,
             4194304 =>             295947,
             8388608 =>             564163,
            16777216 =>            1077871,
            33554432 =>            2063689,
            67108864 =>            3957809,
           134217728 =>            7603553,
           268435456 =>           14630843,
           536870912 =>           28192750,
          1073741824 =>           54400028,
          2147483648 =>          105097565,
          4294967296 =>          203280221,
          8589934592 =>          393615806,
         17179869184 =>          762939111,
         34359738368 =>         1480206279,
         68719476736 =>         2874398515,
        137438953472 =>         5586502348,
        274877906944 =>        10866266172,
        549755813888 =>        21151907950,
       1099511627776 =>        41203088796,
       2199023255552 =>        80316571436,
       4398046511104 =>       156661034233,
       8796093022208 =>       305761713237,
      17592186044416 =>       597116381732,
      35184372088832 =>      1166746786182,
      70368744177664 =>      2280998753949,
     140737488355328 =>      4461632979717,
     281474976710656 =>      8731188863470,
     562949953421312 =>     17094432576778,
    1125899906842624 =>     33483379603407,
    2251799813685248 =>     65612899915304,
    4503599627370496 =>    128625503610475,
    9007199254740992 =>    252252704148404,
   18014398509481984 =>    494890204904784,
   36028797018963968 =>    971269945245201,
   72057594037927936 =>   1906879381028850,
  144115188075855872 =>   3745011184713964,
  288230376151711744 =>   7357400267843990,
  576460752303423488 =>  14458792895301660,
 1152921504606846976 =>  28423094496953330,
 2305843009213693952 =>  55890484045084135,
 4611686018427387904 => 109932807585469973,
 9223372036854775808 => 216289611853439384,
# Leading up to 2**32-1
4294000000 => 203236859,
4294900000 => 203277205,
4294960000 => 203279882,
4294967000 => 203280211,
4294967200 => 203280218,
4294967290 => 203280220,
4294967295 => 203280221,
# From http://trac.sagemath.org/ticket/7539 plus sieving.
# All these results were verified on with MPU's LMO (28 July 2014).
# 11000000000000000000 => 256890014776557326,
# 12000000000000000000 => 279675001309887227,
# 13000000000000000000 => 302416755645383081,
# 14000000000000000000 => 325118755759814408,
# 15000000000000000000 => 347783970566657581,
# 16000000000000000000 => 370414963651223281,
# 17000000000000000000 => 393013970558176111,
# 18000000000000000000 => 415582957615112220,
# 18400000000000000000 => 424602543873663577,
18440000000000000000 => 425504257754137607,
18446700000000000000 => 425655290520421050,
# 18446740000000000000 => 425656192205366999,
# 18446744000000000000 => 425656282373661946,
# 18446744030000000000 => 425656283049924141,
# 18446744040000000000 => 425656283275356419,
# 18446744050000000000 => 425656283500787632,
# 18446744070000000000 => 425656283951611098,
# 18446744073000000000 => 425656284019227775,
# 18446744073700000000 => 425656284035002496,
# 18446744073709000000 => 425656284035205391,
# 18446744073709550000 => 425656284035217706,
# 18446744073709551000 => 425656284035217730,
18446744073709551615 => 425656284035217743,
#
);

if (!$use64) {
  delete @pivals{ grep { $_ > ~0 } keys %pivals };
}

plan tests => 5 + scalar(keys %pivals);

# Test prime counts using sampling
diag "Sampling small prime counts, should take < 1 minute";
{
  my $countstr;
  $countstr = join(" ", map { prime_count($_) } 1 .. 100000);
  is(sha256_hex($countstr), "cdbc5c94a927d0d9481cb26b3d3e60c0617a4be65ce9db3075c0363c7a81ef52", "prime counts 1..10^5");
  $countstr = join(" ", map { prime_count(100*$_ + ($_%101)) } 1000 .. 100000);
  is(sha256_hex($countstr), "73a0b71dedff9611e06fd57e52b88c8afd7f86b5351e4950b2dd5c1d68845b6e", "prime counts 10^5..10^7 (sample 100)");
  $countstr = join(" ", map { prime_count(10000*$_ + ($_%9973)) } 1000 .. 10000);
  is(sha256_hex($countstr), "d73736c54362136aa0a48bab44b55004b2e63e0d1d03a6cbe1aab42c6a579d0c", "prime counts 10^7..10^8 (sample 10k)");
  $countstr = join(" ", map { prime_count(500000*$_ + 250837 + $_) } 200 .. 2000);
  is(sha256_hex($countstr), "00a580b2f52b661f065f5ce49bd2aeacb3b169d8903cf824b65731441e40f0b9", "prime counts 10^8..10^9 (sample 500k)");
  SKIP: {
    skip "Skipping 10^9 to 10^10 if 32-bit", 1 unless $use64;
    $countstr = join(" ", map { prime_count(10000000*$_ + 250837 + $_) } 100 .. 1000);
    is(sha256_hex($countstr), "9fd78debf4b510ee6d230cabf314ebef5eb253ee63d5df658e45414613f7b8c2", "prime counts 10^9..10^10 (sample 10M)");
  }
}

diag "Selected prime counts, will take hours to complete"
  if $use64;
foreach my $n (sort {$a <=> $b} keys %pivals) {
  my $pin = $pivals{$n};
  is( prime_count($n), $pin, "Pi($n) = $pin" );
}
