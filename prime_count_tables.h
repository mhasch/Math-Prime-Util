#ifndef MPU_PC_TABLES_H
#define MPU_PC_TABLES_H

#include "ptypes.h"

/* These tables let us have fast answers up to 3000M for the cost of ~4k of
 * static data/code.  We can get a 4 to 100x speedup here.  We don't want to
 * push this idea too far because LMO/Lehmer is faster past 50M or so. */

#define NSTEP_STEP_0   3000
#define NSTEP_START_0  0
#define NSTEP_COUNT_0  3
#define NSTEP_BASE_0   219
static const unsigned char step_counts_0[] =
{208,134,115,102,97,91,77,89,74,65,74,67,64,66,64,52,57,59,63,56,44,52,44,55,46,50,44,46,41,44,52,49,34,42,39,31,43,34,37,37,43,36,39,32,30,46,37,27,29,38,44,27,22,35,22,25,28,30,34,37,22,34,27,25,28,29,21,24,24,41,20,22,21,30,25,21,42,6,17,20,28,26,32,20,16,18,20,17,26,28,26,15,19,26,20,0,27,4,23,5};
#define NSTEP_NUM_0  (sizeof(step_counts_0)/sizeof(step_counts_0[0]))

#define NSTEP_STEP_1   6000
#define NSTEP_START_1  300000
#define NSTEP_COUNT_1  25997
#define NSTEP_BASE_1   377
static const unsigned char step_counts_1[] =
{115,82,116,101,108,92,93,98,95,90,84,73,95,86,87,103,77,75,81,102,86,87,97,97,64,82,62,85,96,89,63,98,88,72,80,71,101,83,72,69,69,81,68,71,73,84,83,93,59,75,78,75,90,59,56,78,49,75,69,67,81,61,61,85,78,65,55,86,76,47,81,70,69,55,49,73,70,70,72,60,70,63,77,55,65,61,65,84,65,47,61,59,61,57,82,56,67,61,57,53,54,87,42,66,66,54,58,48,54,45,68,64,41,50,51,53,66,70,63,56,66,45,57,51,60,35,51,48,54,63,54,51,71,50,69,68,41,45,66,47,41,57,56,79,44,52,72,60,60,45,28,45,69,36,50,33,48,53,41,71,55,61,34,52,63,31,49,43,50,43,57,43,45,61,20,60,44,45,41,71,42,41,60,56,31,33,35,61,51,58,40,47,54,50,43,24,66,42,63,28,72,53,42,30,42,28,47,38,43,56,36,37,45,30,42,33,38,62,23,48,42,52,50,28,37,54,27,57,40,56,32,31,44,50,42,32,40,39,27,42,30,63,40,9,42,43,49,37,38,49,33,53,26,41,56,41,12,56,35,54,50,41,34,38,41,40,29,35,52,35,36,58,23,51,35,43,32,20,22,25,43,41,50,35,55,43,36,30,52,27,30,26,35,44,41,25,25,39,36,23,48,37,36,24,49,18,43,42,31,59,24,24,47,18,38,34,14,46,30,16,30,45,35,27,36,27,51,39,56,25,13,34,28,42,35,18,13,43,23,23,36,15,33,39,40,15,43,34,30,41,25,9,52,31,22,29,22,28,48,33,36,17,22,20,47,17,32,35,33,23,48,40,9,25,32,31,33,23,28,49,43,27,35,14,18,47,12,28,51,11,46,30,38,15,32,17,28,33,30,39,29,25,39,33,8,15,28,33,14,25,39,27,23,20,20,29,31,30,68,26,37,13,55,29,23,26,12,35,22,0,29,26,15,27,39,11,35,22,18,43,1,36,0,38,35,18,33,28,22,31};
#define NSTEP_NUM_1  (sizeof(step_counts_1)/sizeof(step_counts_1[0]))

#define NSTEP_STEP_2   15000
#define NSTEP_START_2  3000000
#define NSTEP_COUNT_2  216816
#define NSTEP_BASE_2   871
static const unsigned char step_counts_2[] =
{143,107,131,112,148,155,116,149,128,120,134,132,154,156,139,152,106,140,130,112,135,133,117,84,143,139,144,119,133,152,92,103,110,103,111,103,104,147,105,129,168,138,100,98,129,131,143,122,140,112,94,118,103,127,150,110,124,107,102,149,105,137,122,105,106,92,102,116,129,155,94,130,118,121,82,88,117,135,114,115,123,112,101,109,115,75,120,115,88,102,98,114,105,91,147,129,130,115,120,105,98,97,83,113,113,108,110,121,92,113,83,122,109,112,99,118,85,114,85,96,106,95,117,98,113,119,131,91,106,110,114,128,104,87,91,102,93,100,107,100,89,97,121,80,105,70,115,99,101,127,95,95,94,101,85,102,97,93,126,79,84,101,92,110,87,86,92,79,90,86,79,104,101,88,86,91,77,81,87,123,93,99,92,88,76,73,93,91,82,101,76,85,128,100,122,98,85,78,77,86,109,112,54,98,72,82,105,90,74,94,93,95,59,112,61,84,94,98,107,111,74,113,80,78,58,63,90,86,66,71,108,69,86,90,93,80,83,90,113,75,101,75,76,55,96,58,97,101,98,81,99,71,54,89,92,84,95,119,88,75,72,79,92,91,101,67,75,79,108,107,54,86,81,109,65,29,96,84,61,80,77,78,86,65,95,88,73,75,76,55,88,90,59,64,83,84,90,49,89,58,63,60,94,100,47,70,99,76,82,78,72,74,88,64,96,43,71,48,96,52,103,47,102,74,85,89,43,87,81,77,59,75,70,74,60,43,85,90,51,55,55,106,47,82,60,101,51,93,76,74,48,75,71,71,74,65,101,48,69,66,68,59,40,78,59,84,72,85,92,50,77,98,62,86,65,76,64,75,49,78,79,78,68,63,91,78,60,37,70,64,46,73,64,50,90,80,68,32,72,92,15,55,65,52,71,85,71,35,49,91,42,91,60,60,94,73,62,65,66,66,71,46,61,87,55,65,44,69,36,74,39,65,68,65,56,58,65,60,100,70,46,73,47,75,75,58,36,46,86,72,46,42,73,70,58,61,26,73,50,61,37,61,66,45,58,27,48,66,73,73,75,48,67,54,58,53,73,48,50,25,53,72,52,62,82,43,46,64,59,49,63,46,82,55,76,64,54,76,48,73,72,22,58,70,64,55,43,41,80,71,36,91,73,64,65,41,52,25,55,47,56,39,85,56,49,45,83,31,68,81,54,33,62,33,44,51,73,63,58,69,69,3,53,60,76,63,61,36,43,60,51,21,85,20,66,47,58,34,48,50,39,68,37,74,68,25,64,22,71,82,50,54,49,69,97,8,70,41,27,73,40,38,54,59,31,77,60,43,35,32,67,60,33,52,54,52,88,46,46,34,43,43,44,63,52,38,29,57,40,82,20,37,55,38,61,56,33,53,38,73,77,32,16,74,83,36,52,73,39,47,58,39,38,10,80,9,62,25,46,50,57,56,40,38,39,55,50,71,52,57,47,67,31,34,62,57,47,55,16,40,30,33,30,48,45,8,72,63,10,50,15,47,3,62,31,57,35,27,58,65,47,48,24,35,48,49,38,69,28,35,72,37,31,38,36,50,16,28,48,42,24,43,36,33,44,71,33,63,38,27,53,80,26,45,49,16,70,28,35,64,38,31,53,48,44,61,63,52,30,33,14,22,13,52,34,38,33,23,78,29,59,47,41,28,33,23,11,59,31,48,50,51,45,42,18,61,77,37,56,57,9,43,44,25,27,48,41,12,42,42,39,60,35,40,9,41,16,46,64,22,39,45,30,49,70,32,44,22,39,48,36,23,33,11,34,34,63,0,26,40};
#define NSTEP_NUM_2  (sizeof(step_counts_2)/sizeof(step_counts_2[0]))

#define NSTEP_STEP_3   30000
#define NSTEP_START_3  15000000
#define NSTEP_COUNT_3  970704
#define NSTEP_BASE_3   1648
static const unsigned char step_counts_3[] =
{173,179,154,149,165,182,133,171,192,169,164,178,124,133,127,191,180,188,186,164,173,155,177,168,147,153,140,170,216,147,169,142,176,146,150,175,120,170,144,149,176,175,163,155,118,151,151,196,128,192,133,121,170,194,142,163,142,182,151,190,147,141,138,175,159,212,165,159,148,170,133,133,99,134,168,142,181,205,116,172,170,151,187,163,171,157,131,177,94,160,145,114,175,144,116,171,129,163,207,159,117,144,77,174,154,136,88,213,168,149,187,86,135,178,125,110,127,132,150,171,159,174,100,146,166,154,116,156,158,108,137,161,150,132,142,126,107,164,138,151,116,149,113,158,130,158,179,155,129,113,131,105,96,180,125,127,169,114,169,156,141,142,140,133,150,130,144,155,142,135,126,118,182,70,143,128,135,103,173,121,112,122,105,171,123,136,117,150,124,183,161,115,130,102,138,151,106,135,102,144,166,148,108,120,140,111,107,104,146,176,117,116,144,115,119,189,97,113,118,154,137,105,138,142,148,135,108,142,127,118,163,165,119,104,190,72,84,125,121,93,106,106,119,151,92,117,117,108,118,119,134,152,147,115,107,144,152,124,104,99,103,159,135,144,100,113,156,132,114,110,98,145,109,106,108,161,142,102,156,71,90,150,134,91,156,107,97,126,137,119,84,111,122,110,77,128,158,117,95,131,120,138,118,84,113,138,108,157,105,148,119,123,114,140,90,93,128,128,94,119,114,95,174,111,109,150,85,78,122,116,84,105,130,133,60,138,140,118,66,102,70,80,118,127,103,95,127,69,169,90,101,123,129,77,138,56,139,119,132,104,136,111,123,93,112,108,113,111,105,112,123,101,88,114,49,134,104,113,92,134,156,66,131,122,135,82,112,115,127,80,101,59,119,122,82,124,112,127,115,107,110,79,147,105,130,109,57,116,75,85,92,121,74,126,131,79,85,121,112,155,86,104,60,97,178,71,97,72,71,140,118,107,105,99,141,49,105,99,98,67,142,103,113,146,84,74,91,99,81,142,97,117,96,73,127,94,64,125,65,114,74,97,92,117,77,90,99,109,66,106,103,85,60,116,36,120,160,92,130,90,42,80,116,81,113,85,90,94,113,121,133,58,54,72,113,137,103,122,113,115,120,98,134,67,127,60,117,96,88,121,104,111,86,92,21,101,78,134,82,129,79,152,98,81,85,76,83,110,109,110,88,82,35,114,50,79,48,126,72,66,99,74,138,88,82,79,87,82,72,64,68,83,130,88,83,114,82,48,87,88,112,121,86,80,89,94,79,61,78,100,121,118,57,58,96,84,106,84,96,94,89,80,97,81,93,94,100,94,77,94,77,73,84,87,46,78,106,106,116,77,78,40,96,77,95,95,80,73,113,95,109,77,117,77,92,83,59,53,121,67,53,98,80,90,81,118,57,115,97,85,75,18,84,72,77,50,90,57,44,66,77,55,88,59,52,57,97,56,105,84,118,75,67,86,50,27,80,83,58,107,54,83,120,86,68,114,56,54,65,58,91,95,53,98,99,47,95,95,48,104,102,76,58,63,109,62,64,73,110,71,53,84,110,59,82,50,51,79,60,111,126,27,71,94,95,44,26,97,117,104,76,89,76,30,83,106,66,75,32,122,82,60,41,51,48,127,68,35,92,35,26,92,99,86,74,77,110,128,55,65,51,37,81,67,67,79,107,29,67,96,91,97,25,104,78,71,59,77,57,73,38,94,37,81,55,69,68,63,112,69,88,75,118,51,67,105,114,57,48,74,73,70,63,109,22,46,74,47,67,86,88,96,74,79,95,101,43,114,44,46,53,64,73,81,77,57,66,83,56,138,100,59,55,93,65,44,95,81,44,81,130,59,83,38,57,89,63,37,71,47,68,17,63,78,40,66,84,79,77,45,38,43,143,70,83,89,46,40,73,90,36,49,29,74,45,57,67,126,69,104,60,78,48,10,41,68,74,61,35,112,60,69,87,42,56,28,59,96,38,43,36,118,42,65,57,34,30,31,65,83,58,63,55,89,106,40,64,0,60,30};
#define NSTEP_NUM_3  (sizeof(step_counts_3)/sizeof(step_counts_3[0]))

#define NSTEP_STEP_4   30000
#define NSTEP_START_4  42000000
#define NSTEP_COUNT_4  2547620
#define NSTEP_BASE_4   1598
static const unsigned char step_counts_4[] =
{84,119,116,106,140,117,134,80,152,159,106,103,125,80,108,130,110,104,106,82,108,152,85,104,106,101,157,67,98,71,93,112,87,89,90,132,142,95,142,75,119,93,96,112,123,108,100,107,121,131,112,135,109,80,85,78,101,113,84,108,100,114,100,78,123,163,113,88,117,78,77,113,114,115,78,149,126,84,93,88,121,113,94,91,108,131,134,96,88,150,107,120,121,83,64,137,87,92,127,83,110,156,105,101,96,67,92,144,109,135,161,124,79,84,145,135,76,136,65,140,105,106,104,99,112,128,41,80,133,139,122,103,61,124,95,100,83,70,102,108,123,84,61,97,127,102,92,102,76,125,108,84,105,135,107,123,92,69,96,132,114,76,110,105,102,96,113,99,35,86,129,115,110,99,78,126,93,110,70,121,90,62,128,113,92,96,105,80,52,107,101,68,101,105,105,170,68,77,89,73,109,42,92,113,108,100,68,65,108,96,111,116,100,91,55,100,137,103,45,114,121,75,90,77,74,67,122,138,79,96,84,115,93,84,87,84,115,80,98,118,124,80,101,72,115,108,109,110,73,156,101,88,129,118,76,90,84,85,122,90,71,134,111,97,71,121,52,84,89,92,145,77,49,113,87,91,108,113,85,74,77,104,97,110,93,120,78,107,61,117,72,137,98,79,126,89,68,77,73,102,59,70,87,141,61,78,85,116,91,79,91,92,153,87,74,51,125,87,132,97,82,64,58,86,128,89,126,143,58,86,96,99,77,90,100,106,72,89,51,116,90,67,64,86,103,95,102,78,79,97,72,106,63,104,131,59,74,99,100,86,109,60,113,89,80,78,86,94,69,136,54,132,90,57,99,98,127,86,79,59,95,73,49,94,70,55,87,60,137,61,114,81,90,74,35,104,123,68,123,94,60,94,110,71,97,51,61,78,98,78,91,82,45,71,94,81,63,129,65,119,99,122,53,55,80,103,75,72,70,18,63,162,81,99,96,127,105,57,74,77,113,70,61,91,78,83,82,105,80,74,39,64,103,96,105,91,105,98,123,41,114,92,48,88,60,82,95,76,103,109,111,98,131,57,47,109,89,55,77,70,45,49,108,49,106,88,108,66,108,137,108,80,109,92,60,42,113,97,50,78,82,60,121,94,79,60,79,74,106,124,97,106,76,57,58,58,101,101,70,79,65,75,54,87,72,61,76,64,88,91,70,84,48,70,100,101,70,94,65,70,58,117,82,39,90,113,65,74,73,71,103,97,72,106,86,44,61,104,87,117,129,46,90,83,64,58,48,127,33,102,64,34,120,49,52,64,89,106,46,22,117,76,70,95,95,52,89,83,69,58,104,41,121,77,107,63,80,56,68,87,72,64,73,27,103,102,39,133,59,66,106,75,88,89,53,75,75,68,62,74,139,72,81,54,108,90,77,110,90,70,71,69,82,90,77,58,45,76,23,64,92,78,70,40,39,95,63,62,106,89,63,52,37,90,49,109,54,72,69,55,95,82,80,46,104,52,105,59,86,90,98,69,52,61,70,60,101,110,70,38,98,77,55,75,55,19,102,41,76,82,86,59,121,81,49,60,103,55,85,51,92,19,123,48,46,86,88,79,96,58,44,66,90,76,108,82,42,86,81,69,54,81,81,35,98,67,134,89,51,96,85,71,58,55,78,78,101,60,55,73,69,59,118,39,83,60,99,58,71,57,79,58,19,29,72,81,61,45,38,72,65,50,75,81,80,75,52,134,44,62,58,50,39,48,81,72,89,76,41,30,145,72,132,44,55,60,63,69,0,113,44,58,63,95,70,77,67,64,86,92,63,112,70,68,25,107,91,88,44,71,130,66,108,53,52,65,93,52,51,92,65,77,108,37,58,62,53,44,99,84,34,56,54,82,74,54,73,45,38,80,86,82,97,81,38,78,95,65,108,61,55,65,90,64,47,75,53,92,84,18,66,84,63,90,56,70,64,49,88,26,87,54,36,108,73,41,76,44,45,79,65,39,110,39,49,83,54,47,90,47,71,36,64,31,73,76,58,34,72,102};
#define NSTEP_NUM_4  (sizeof(step_counts_4)/sizeof(step_counts_4[0]))

#define NSTEP_STEP_5   60000
#define NSTEP_START_5  69000000
#define NSTEP_COUNT_5  4062674
#define NSTEP_BASE_5   3184
static const unsigned char step_counts_5[] =
{133,125,135,92,121,183,192,167,142,141,154,158,155,149,87,125,105,111,139,176,142,143,132,180,170,123,155,71,135,74,132,127,161,116,146,148,102,169,88,129,247,122,129,149,142,105,73,150,134,100,150,175,154,189,171,131,131,82,159,95,103,176,73,181,135,133,154,145,96,88,122,152,121,98,109,185,107,175,130,96,151,156,94,108,45,159,122,101,111,159,131,84,100,146,112,141,146,81,184,99,94,166,109,177,120,146,123,161,96,100,156,122,122,166,134,144,161,90,110,125,84,91,155,118,48,147,77,79,98,120,141,126,142,150,120,117,138,106,87,146,81,114,119,110,86,123,123,123,147,102,149,101,151,108,45,104,80,93,136,157,89,112,134,118,91,117,82,152,122,111,100,98,91,168,95,101,115,154,108,92,109,99,133,24,155,103,63,166,141,99,147,119,101,80,116,146,96,167,94,133,175,170,115,78,125,84,149,141,53,131,93,117,90,93,139,102,151,129,113,47,68,90,112,109,77,127,93,136,137,130,151,96,98,146,47,84,63,99,113,70,115,110,112,81,65,166,95,137,150,158,77,40,81,64,96,134,84,143,116,64,78,100,112,76,82,100,85,72,106,108,106,78,129,158,83,121,66,120,86,106,93,120,93,83,140,72,80,88,71,141,122,130,76,130,48,102,122,100,82,77,134,63,108,114,95,92,8,120,111,88,100,63,95,96,119,86,111,162,82,84,196,86,71,130,38,0,109,123,77,96,142,101,110,79,77,126,111,111,101,22,105,62,71,87,31,45,33,134,77,92};
#define NSTEP_NUM_5  (sizeof(step_counts_5)/sizeof(step_counts_5[0]))

#define NSTEP_STEP_6   30000000
#define NSTEP_START_6  90000000
#define NSTEP_COUNT_6  5216954
#define NSTEP_BASE_6   1374445
static const unsigned int step_counts_6[] =
{250249,228303,211544,196796,185473,175395,166496,158705,151368,145477,138824,134114,128941,123383,119684,115460,111972,108081,104496,101132,97856,94688,91850,90266,86778,84033,80882,79773,77438,74948,73167,70584,68840,67823,64066,63243,61158,59178,58193,56713,54713,53489,51746,50004,48701,47453,47183,45074,43201,41829,40383,40029,38091,37702,35704,35029,34402,32174,31418,30254,29375,28357,27770,27014,25527,24242,23523,22947,21580,20866,19636,19169,19257,17300,16505,15411,14800,13936,13112,12642,11840,11644,10910,9214,8585,7729,7683,6111,5495,5543,4736,3855,3588,2529,1837,1201,0};
#define NSTEP_NUM_6  (sizeof(step_counts_6)/sizeof(step_counts_6[0]))

#define NSTEP_IF(name) \
  (high < (NSTEP_START_##name + NSTEP_STEP_##name*(NSTEP_NUM_##name+1)))

#define NSTEP_SEARCH(name) \
  { \
    UV i, maxi; \
    low = NSTEP_START_##name; \
    scount = NSTEP_COUNT_##name; \
    maxi = (high-low)/NSTEP_STEP_##name; \
    for (i = 0;  i < maxi && i < NSTEP_NUM_##name;  i++) { \
      scount += NSTEP_BASE_##name + step_counts_##name[i]; \
      low += NSTEP_STEP_##name; \
    } \
  }

#define APPLY_TABLES \
  if (low == 7 && high >= 3000) { \
    UV scount = 0; \
    if      (NSTEP_IF(0)) { NSTEP_SEARCH(0); } \
    else if (NSTEP_IF(1)) { NSTEP_SEARCH(1); } \
    else if (NSTEP_IF(2)) { NSTEP_SEARCH(2); } \
    else if (NSTEP_IF(3)) { NSTEP_SEARCH(3); } \
    else if (NSTEP_IF(4)) { NSTEP_SEARCH(4); } \
    else if (NSTEP_IF(5)) { NSTEP_SEARCH(5); } \
    else                  { NSTEP_SEARCH(6); } \
    count = count + scount - 3; /* step counts start at 2 */ \
  }

#endif
