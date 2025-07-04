/* ------------------------------------------------------------
name: "hole"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _hole -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___hole_H__
#define  ___hole_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _hole
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

const static int i_holeSIG0Wave0[2048] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087,5099,5101,5107,5113,5119,5147,5153,5167,5171,5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443,5449,5471,5477,5479,5483,5501,5503,5507,5519,5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133,6143,6151,6163,6173,6197,6199,6203,6211,6217,6221,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473,6481,6491,6521,6529,6547,6551,6553,6563,6569,6571,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833,6841,6857,6863,6869,6871,6883,6899,6907,6911,6917,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207,7211,7213,7219,7229,7237,7243,7247,7253,7283,7297,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561,7573,7577,7583,7589,7591,7603,7607,7621,7639,7643,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919,7927,7933,7937,7949,7951,7963,7993,8009,8011,8017,8039,8053,8059,8069,8081,8087,8089,8093,8101,8111,8117,8123,8147,8161,8167,8171,8179,8191,8209,8219,8221,8231,8233,8237,8243,8263,8269,8273,8287,8291,8293,8297,8311,8317,8329,8353,8363,8369,8377,8387,8389,8419,8423,8429,8431,8443,8447,8461,8467,8501,8513,8521,8527,8537,8539,8543,8563,8573,8581,8597,8599,8609,8623,8627,8629,8641,8647,8663,8669,8677,8681,8689,8693,8699,8707,8713,8719,8731,8737,8741,8747,8753,8761,8779,8783,8803,8807,8819,8821,8831,8837,8839,8849,8861,8863,8867,8887,8893,8923,8929,8933,8941,8951,8963,8969,8971,8999,9001,9007,9011,9013,9029,9041,9043,9049,9059,9067,9091,9103,9109,9127,9133,9137,9151,9157,9161,9173,9181,9187,9199,9203,9209,9221,9227,9239,9241,9257,9277,9281,9283,9293,9311,9319,9323,9337,9341,9343,9349,9371,9377,9391,9397,9403,9413,9419,9421,9431,9433,9437,9439,9461,9463,9467,9473,9479,9491,9497,9511,9521,9533,9539,9547,9551,9587,9601,9613,9619,9623,9629,9631,9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829,9833,9839,9851,9857,9859,9871,9883,9887,9901,9907,9923,9929,9931,9941,9949,9967,9973,10007,10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,10103,10111,10133,10139,10141,10151,10159,10163,10169,10177,10181,10193,10211,10223,10243,10247,10253,10259,10267,10271,10273,10289,10301,10303,10313,10321,10331,10333,10337,10343,10357,10369,10391,10399,10427,10429,10433,10453,10457,10459,10463,10477,10487,10499,10501,10513,10529,10531,10559,10567,10589,10597,10601,10607,10613,10627,10631,10639,10651,10657,10663,10667,10687,10691,10709,10711,10723,10729,10733,10739,10753,10771,10781,10789,10799,10831,10837,10847,10853,10859,10861,10867,10883,10889,10891,10903,10909,10937,10939,10949,10957,10973,10979,10987,10993,11003,11027,11047,11057,11059,11069,11071,11083,11087,11093,11113,11117,11119,11131,11149,11159,11161,11171,11173,11177,11197,11213,11239,11243,11251,11257,11261,11273,11279,11287,11299,11311,11317,11321,11329,11351,11353,11369,11383,11393,11399,11411,11423,11437,11443,11447,11467,11471,11483,11489,11491,11497,11503,11519,11527,11549,11551,11579,11587,11593,11597,11617,11621,11633,11657,11677,11681,11689,11699,11701,11717,11719,11731,11743,11777,11779,11783,11789,11801,11807,11813,11821,11827,11831,11833,11839,11863,11867,11887,11897,11903,11909,11923,11927,11933,11939,11941,11953,11959,11969,11971,11981,11987,12007,12011,12037,12041,12043,12049,12071,12073,12097,12101,12107,12109,12113,12119,12143,12149,12157,12161,12163,12197,12203,12211,12227,12239,12241,12251,12253,12263,12269,12277,12281,12289,12301,12323,12329,12343,12347,12373,12377,12379,12391,12401,12409,12413,12421,12433,12437,12451,12457,12473,12479,12487,12491,12497,12503,12511,12517,12527,12539,12541,12547,12553,12569,12577,12583,12589,12601,12611,12613,12619,12637,12641,12647,12653,12659,12671,12689,12697,12703,12713,12721,12739,12743,12757,12763,12781,12791,12799,12809,12821,12823,12829,12841,12853,12889,12893,12899,12907,12911,12917,12919,12923,12941,12953,12959,12967,12973,12979,12983,13001,13003,13007,13009,13033,13037,13043,13049,13063,13093,13099,13103,13109,13121,13127,13147,13151,13159,13163,13171,13177,13183,13187,13217,13219,13229,13241,13249,13259,13267,13291,13297,13309,13313,13327,13331,13337,13339,13367,13381,13397,13399,13411,13417,13421,13441,13451,13457,13463,13469,13477,13487,13499,13513,13523,13537,13553,13567,13577,13591,13597,13613,13619,13627,13633,13649,13669,13679,13681,13687,13691,13693,13697,13709,13711,13721,13723,13729,13751,13757,13759,13763,13781,13789,13799,13807,13829,13831,13841,13859,13873,13877,13879,13883,13901,13903,13907,13913,13921,13931,13933,13963,13967,13997,13999,14009,14011,14029,14033,14051,14057,14071,14081,14083,14087,14107,14143,14149,14153,14159,14173,14177,14197,14207,14221,14243,14249,14251,14281,14293,14303,14321,14323,14327,14341,14347,14369,14387,14389,14401,14407,14411,14419,14423,14431,14437,14447,14449,14461,14479,14489,14503,14519,14533,14537,14543,14549,14551,14557,14561,14563,14591,14593,14621,14627,14629,14633,14639,14653,14657,14669,14683,14699,14713,14717,14723,14731,14737,14741,14747,14753,14759,14767,14771,14779,14783,14797,14813,14821,14827,14831,14843,14851,14867,14869,14879,14887,14891,14897,14923,14929,14939,14947,14951,14957,14969,14983,15013,15017,15031,15053,15061,15073,15077,15083,15091,15101,15107,15121,15131,15137,15139,15149,15161,15173,15187,15193,15199,15217,15227,15233,15241,15259,15263,15269,15271,15277,15287,15289,15299,15307,15313,15319,15329,15331,15349,15359,15361,15373,15377,15383,15391,15401,15413,15427,15439,15443,15451,15461,15467,15473,15493,15497,15511,15527,15541,15551,15559,15569,15581,15583,15601,15607,15619,15629,15641,15643,15647,15649,15661,15667,15671,15679,15683,15727,15731,15733,15737,15739,15749,15761,15767,15773,15787,15791,15797,15803,15809,15817,15823,15859,15877,15881,15887,15889,15901,15907,15913,15919,15923,15937,15959,15971,15973,15991,16001,16007,16033,16057,16061,16063,16067,16069,16073,16087,16091,16097,16103,16111,16127,16139,16141,16183,16187,16189,16193,16217,16223,16229,16231,16249,16253,16267,16273,16301,16319,16333,16339,16349,16361,16363,16369,16381,16411,16417,16421,16427,16433,16447,16451,16453,16477,16481,16487,16493,16519,16529,16547,16553,16561,16567,16573,16603,16607,16619,16631,16633,16649,16651,16657,16661,16673,16691,16693,16699,16703,16729,16741,16747,16759,16763,16787,16811,16823,16829,16831,16843,16871,16879,16883,16889,16901,16903,16921,16927,16931,16937,16943,16963,16979,16981,16987,16993,17011,17021,17027,17029,17033,17041,17047,17053,17077,17093,17099,17107,17117,17123,17137,17159,17167,17183,17189,17191,17203,17207,17209,17231,17239,17257,17291,17293,17299,17317,17321,17327,17333,17341,17351,17359,17377,17383,17387,17389,17393,17401,17417,17419,17431,17443,17449,17467,17471,17477,17483,17489,17491,17497,17509,17519,17539,17551,17569,17573,17579,17581,17597,17599,17609,17623,17627,17657,17659,17669,17681,17683,17707,17713,17729,17737,17747,17749,17761,17783,17789,17791,17807,17827,17837,17839,17851,17863};
struct _holeSIG0 {
	int i_holeSIG0Wave0_idx;
	
	int getNumInputs_holeSIG0() {
		return 0;
	}
	int getNumOutputs_holeSIG0() {
		return 1;
	}
	
	void instanceInit_holeSIG0(int sample_rate) {
		i_holeSIG0Wave0_idx = 0;
	}
	
	void fill_holeSIG0(int count, int* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = i_holeSIG0Wave0[i_holeSIG0Wave0_idx];
			i_holeSIG0Wave0_idx = (1 + i_holeSIG0Wave0_idx) % 2048;
		}
	}

};

static _holeSIG0* new_holeSIG0() { return (_holeSIG0*)new _holeSIG0(); }
static void delete_holeSIG0(_holeSIG0* dsp) { delete dsp; }

static float _hole_faustpower2_f(float value) {
	return value * value;
}
static int itbl0_holeSIG0[2048];

struct _hole final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	int iVec0[2];
	FAUSTFLOAT fHslider7;
	float fConst2;
	FAUSTFLOAT fHslider8;
	float fRec22[2];
	float fRec23[2];
	int IOTA0;
	float fVec1[16384];
	float fRec55[2];
	float fVec2[2];
	float fRec54[2];
	float fRec52[2];
	float fVec3[16384];
	float fRec57[2];
	float fVec4[2];
	float fRec56[2];
	float fRec53[2];
	float fVec5[16384];
	float fRec58[2];
	float fVec6[2];
	float fRec51[2];
	float fRec49[2];
	float fVec7[16384];
	float fRec60[2];
	float fVec8[2];
	float fRec59[2];
	float fRec50[2];
	float fVec9[16384];
	float fRec61[2];
	float fVec10[2];
	float fRec48[2];
	float fRec46[2];
	float fVec11[16384];
	float fRec63[2];
	float fVec12[2];
	float fRec62[2];
	float fRec47[2];
	float fVec13[16384];
	float fRec64[2];
	float fVec14[2];
	float fRec45[2];
	float fRec43[2];
	float fVec15[16384];
	float fRec66[2];
	float fVec16[2];
	float fRec65[2];
	float fRec44[2];
	float fVec17[16384];
	float fRec67[2];
	float fVec18[2];
	float fRec42[2];
	float fRec40[2];
	float fVec19[16384];
	float fRec69[2];
	float fVec20[2];
	float fRec68[2];
	float fRec41[2];
	float fVec21[1024];
	float fVec22[16384];
	float fRec70[2];
	float fVec23[2];
	float fRec39[2];
	float fVec24[1024];
	float fVec25[16384];
	float fRec72[2];
	float fVec26[2];
	float fRec71[2];
	float fVec27[16384];
	float fRec73[2];
	float fVec28[2];
	float fRec38[2];
	float fRec36[2];
	float fVec29[16384];
	float fRec75[2];
	float fVec30[2];
	float fRec74[2];
	float fRec37[2];
	float fVec31[16384];
	float fRec76[2];
	float fVec32[2];
	float fRec35[2];
	float fRec33[2];
	float fVec33[16384];
	float fRec78[2];
	float fVec34[2];
	float fRec77[2];
	float fRec34[2];
	float fVec35[16384];
	float fRec79[2];
	float fVec36[2];
	float fRec32[2];
	float fRec30[2];
	float fVec37[16384];
	float fRec81[2];
	float fVec38[2];
	float fRec80[2];
	float fRec31[2];
	float fVec39[16384];
	float fRec82[2];
	float fVec40[2];
	float fRec29[2];
	float fRec27[2];
	float fVec41[16384];
	float fRec84[2];
	float fVec42[2];
	float fRec83[2];
	float fRec28[2];
	float fVec43[16384];
	float fRec85[2];
	float fVec44[2];
	float fRec26[2];
	float fRec24[2];
	float fVec45[16384];
	float fRec87[2];
	float fVec46[2];
	float fRec86[2];
	float fRec25[2];
	float fVec47[16384];
	float fVec48[16384];
	float fRec88[2];
	float fVec49[2];
	float fRec21[2];
	float fRec20[2];
	float fRec19[3];
	float fRec18[3];
	float fVec50[2];
	float fRec17[2];
	float fRec16[3];
	float fRec15[3];
	FAUSTFLOAT fHslider9;
	float fRec91[2];
	float fRec90[3];
	float fRec89[3];
	FAUSTFLOAT fHslider10;
	float fRec95[2];
	float fRec94[3];
	float fRec93[3];
	float fRec92[3];
	float fVec51[1024];
	float fRec14[2];
	float fVec52[16384];
	float fVec53[16384];
	float fRec102[2];
	float fVec54[2];
	float fRec101[2];
	float fRec100[2];
	float fRec99[3];
	float fRec98[3];
	float fRec97[3];
	float fRec108[2];
	float fRec107[3];
	float fRec106[3];
	float fVec55[2];
	float fRec105[2];
	float fRec104[3];
	float fRec103[3];
	float fRec111[2];
	float fRec110[3];
	float fRec109[3];
	float fVec56[1024];
	float fRec96[2];
	float fVec57[16384];
	float fVec58[2];
	float fRec13[2];
	float fRec11[2];
	float fVec59[16384];
	float fRec113[2];
	float fVec60[2];
	float fRec112[2];
	float fRec12[2];
	float fVec61[16384];
	float fVec62[2];
	float fRec10[2];
	float fRec8[2];
	float fVec63[16384];
	float fVec64[2];
	float fRec114[2];
	float fRec9[2];
	float fVec65[16384];
	float fVec66[2];
	float fRec7[2];
	float fRec5[2];
	float fVec67[16384];
	float fRec116[2];
	float fVec68[2];
	float fRec115[2];
	float fRec6[2];
	float fVec69[16384];
	float fRec117[2];
	float fVec70[2];
	float fRec4[2];
	float fRec2[2];
	float fVec71[16384];
	float fVec72[2];
	float fRec118[2];
	float fRec3[2];
	float fRec0[2];
	float fRec1[2];
	
	_hole() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _hole -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/fdelay1a:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelay4:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("demos.lib/jprev_demo:author", "Till Bovermann");
		m->declare("demos.lib/jprev_demo:license", "GPL2+");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/version", "1.2.0");
		m->declare("filename", "hole.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "hole");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/jpverb:author", "Julian Parker, bug fixes and minor interface changes by Till Bovermann");
		m->declare("reverbs.lib/jpverb:license", "GPL2+");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		_holeSIG0* sig0 = new_holeSIG0();
		sig0->instanceInit_holeSIG0(sample_rate);
		sig0->fill_holeSIG0(2048, itbl0_holeSIG0);
		delete_holeSIG0(sig0);
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 3.1415927f / fConst0;
		fConst2 = 6.2831855f / fConst0;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.70710677f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(5e+02f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(2e+03f);
		fHslider7 = FAUSTFLOAT(0.1f);
		fHslider8 = FAUSTFLOAT(2.0f);
		fHslider9 = FAUSTFLOAT(1.0f);
		fHslider10 = FAUSTFLOAT(1.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec22[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec23[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 16384; l3 = l3 + 1) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec55[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec54[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec52[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 16384; l8 = l8 + 1) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec57[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec56[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec53[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 16384; l13 = l13 + 1) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec58[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fVec6[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec51[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec49[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 16384; l18 = l18 + 1) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec60[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fVec8[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec59[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec50[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 16384; l23 = l23 + 1) {
			fVec9[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec61[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fVec10[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec48[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec46[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 16384; l28 = l28 + 1) {
			fVec11[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec63[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fVec12[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec62[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec47[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 16384; l33 = l33 + 1) {
			fVec13[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec64[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fVec14[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec45[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec43[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 16384; l38 = l38 + 1) {
			fVec15[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec66[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fVec16[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec65[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec44[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 16384; l43 = l43 + 1) {
			fVec17[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec67[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fVec18[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec42[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec40[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 16384; l48 = l48 + 1) {
			fVec19[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec69[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fVec20[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec68[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec41[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 1024; l53 = l53 + 1) {
			fVec21[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 16384; l54 = l54 + 1) {
			fVec22[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec70[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fVec23[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec39[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 1024; l58 = l58 + 1) {
			fVec24[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 16384; l59 = l59 + 1) {
			fVec25[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec72[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fVec26[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec71[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 16384; l63 = l63 + 1) {
			fVec27[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec73[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fVec28[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec38[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec36[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 16384; l68 = l68 + 1) {
			fVec29[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fRec75[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fVec30[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec74[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec37[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 16384; l73 = l73 + 1) {
			fVec31[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			fRec76[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			fVec32[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fRec35[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec33[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 16384; l78 = l78 + 1) {
			fVec33[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec78[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fVec34[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			fRec77[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec34[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 16384; l83 = l83 + 1) {
			fVec35[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fRec79[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			fVec36[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			fRec32[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec30[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 16384; l88 = l88 + 1) {
			fVec37[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec81[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			fVec38[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec80[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec31[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 16384; l93 = l93 + 1) {
			fVec39[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			fRec82[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fVec40[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fRec29[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec27[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 16384; l98 = l98 + 1) {
			fVec41[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec84[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			fVec42[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec83[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec28[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 16384; l103 = l103 + 1) {
			fVec43[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			fRec85[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fVec44[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fRec26[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			fRec24[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 16384; l108 = l108 + 1) {
			fVec45[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec87[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			fVec46[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fRec86[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			fRec25[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 16384; l113 = l113 + 1) {
			fVec47[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 16384; l114 = l114 + 1) {
			fVec48[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			fRec88[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fVec49[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fRec21[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec20[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 3; l119 = l119 + 1) {
			fRec19[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 3; l120 = l120 + 1) {
			fRec18[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2; l121 = l121 + 1) {
			fVec50[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec17[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 3; l123 = l123 + 1) {
			fRec16[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 3; l124 = l124 + 1) {
			fRec15[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec91[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 3; l126 = l126 + 1) {
			fRec90[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 3; l127 = l127 + 1) {
			fRec89[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			fRec95[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 3; l129 = l129 + 1) {
			fRec94[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 3; l130 = l130 + 1) {
			fRec93[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 3; l131 = l131 + 1) {
			fRec92[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 1024; l132 = l132 + 1) {
			fVec51[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			fRec14[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 16384; l134 = l134 + 1) {
			fVec52[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 16384; l135 = l135 + 1) {
			fVec53[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			fRec102[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fVec54[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			fRec101[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			fRec100[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 3; l140 = l140 + 1) {
			fRec99[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 3; l141 = l141 + 1) {
			fRec98[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 3; l142 = l142 + 1) {
			fRec97[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 2; l143 = l143 + 1) {
			fRec108[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 3; l144 = l144 + 1) {
			fRec107[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 3; l145 = l145 + 1) {
			fRec106[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fVec55[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 2; l147 = l147 + 1) {
			fRec105[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 3; l148 = l148 + 1) {
			fRec104[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 3; l149 = l149 + 1) {
			fRec103[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			fRec111[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 3; l151 = l151 + 1) {
			fRec110[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 3; l152 = l152 + 1) {
			fRec109[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 1024; l153 = l153 + 1) {
			fVec56[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fRec96[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 16384; l155 = l155 + 1) {
			fVec57[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fVec58[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 2; l157 = l157 + 1) {
			fRec13[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			fRec11[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 16384; l159 = l159 + 1) {
			fVec59[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			fRec113[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fVec60[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec112[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 2; l163 = l163 + 1) {
			fRec12[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 16384; l164 = l164 + 1) {
			fVec61[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			fVec62[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec10[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fRec8[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 16384; l168 = l168 + 1) {
			fVec63[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			fVec64[l169] = 0.0f;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			fRec114[l170] = 0.0f;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			fRec9[l171] = 0.0f;
		}
		for (int l172 = 0; l172 < 16384; l172 = l172 + 1) {
			fVec65[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fVec66[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fRec7[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			fRec5[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 16384; l176 = l176 + 1) {
			fVec67[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 2; l177 = l177 + 1) {
			fRec116[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fVec68[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec115[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fRec6[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 16384; l181 = l181 + 1) {
			fVec69[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			fRec117[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fVec70[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec4[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 2; l185 = l185 + 1) {
			fRec2[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 16384; l186 = l186 + 1) {
			fVec71[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 2; l187 = l187 + 1) {
			fVec72[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec118[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec3[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec0[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fRec1[l191] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_hole* clone() {
		return new _hole();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("JPrev");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("Mix");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("earlyDiff", &fHslider0, FAUSTFLOAT(0.70710677f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.99f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("size", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "3", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("t60", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(6e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "4", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("damp", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.999f), FAUSTFLOAT(0.0001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("EQ");
		ui_interface->declare(&fHslider9, "07", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("lowX", &fHslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "08", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("midX", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider10, "09", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("highX", &fHslider10, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "10", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("lowBand", &fHslider4, FAUSTFLOAT(5e+02f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(6e+03f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider6, "11", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("highBand", &fHslider6, FAUSTFLOAT(2e+03f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Mod");
		ui_interface->declare(&fHslider7, "1", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("mDepth", &fHslider7, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider8, "2", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("mFreq", &fHslider8, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(0.99f, float(fHslider0)));
		float fSlow1 = std::cos(fSlow0);
		float fSlow2 = std::max<float>(0.0f, std::min<float>(0.999f, float(fHslider1)));
		float fSlow3 = 1.0f - fSlow2;
		float fSlow4 = std::max<float>(0.5f, std::min<float>(3.0f, float(fHslider2)));
		float fSlow5 = std::pow(1e+01f, -(0.51f * ((1.25f * fSlow4 + -0.25f) / std::max<float>(0.1f, std::min<float>(6e+01f, float(fHslider3))))));
		float fSlow6 = std::tan(fConst1 * std::max<float>(1e+02f, std::min<float>(6e+03f, float(fHslider4))));
		float fSlow7 = 1.0f / fSlow6;
		float fSlow8 = 1.0f / ((fSlow7 + 0.618034f) / fSlow6 + 1.0f);
		float fSlow9 = _hole_faustpower2_f(fSlow6);
		float fSlow10 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider5))) / fSlow9;
		float fSlow11 = (fSlow7 + 1.618034f) / fSlow6 + 1.0f;
		float fSlow12 = 1.0f / (fSlow11 * fSlow9);
		float fSlow13 = 1.0f / (fSlow7 + 1.0f);
		float fSlow14 = std::tan(fConst1 * std::max<float>(1e+03f, std::min<float>(1e+04f, float(fHslider6))));
		float fSlow15 = 1.0f / fSlow14;
		float fSlow16 = (fSlow15 + 0.618034f) / fSlow14 + 1.0f;
		float fSlow17 = 1.0f / fSlow16;
		float fSlow18 = (fSlow15 + 1.618034f) / fSlow14 + 1.0f;
		float fSlow19 = 1.0f / fSlow18;
		float fSlow20 = 1.0f / (fSlow15 + 1.0f);
		float fSlow21 = 1.0f - fSlow15;
		float fSlow22 = 5e+01f * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider7)));
		float fSlow23 = fConst2 * std::max<float>(0.0f, std::min<float>(1e+01f, float(fHslider8)));
		float fSlow24 = std::sin(fSlow23);
		float fSlow25 = std::cos(fSlow23);
		int iSlow26 = itbl0_holeSIG0[int(1e+01f * fSlow4)];
		float fSlow27 = 0.0001f * float(iSlow26);
		int iSlow28 = itbl0_holeSIG0[int(1.1e+02f * fSlow4)];
		float fSlow29 = 0.0001f * float(iSlow28);
		int iSlow30 = itbl0_holeSIG0[int(4e+01f * fSlow4)];
		float fSlow31 = 0.0001f * float(iSlow30);
		int iSlow32 = itbl0_holeSIG0[int(1.4e+02f * fSlow4)];
		float fSlow33 = 0.0001f * float(iSlow32);
		int iSlow34 = itbl0_holeSIG0[int(7e+01f * fSlow4)];
		float fSlow35 = 0.0001f * float(iSlow34);
		int iSlow36 = itbl0_holeSIG0[int(1.7e+02f * fSlow4)];
		float fSlow37 = 0.0001f * float(iSlow36);
		int iSlow38 = itbl0_holeSIG0[int(1e+02f * fSlow4)];
		float fSlow39 = 0.0001f * float(iSlow38);
		int iSlow40 = itbl0_holeSIG0[int(2e+02f * fSlow4)];
		float fSlow41 = 0.0001f * float(iSlow40);
		int iSlow42 = itbl0_holeSIG0[int(1.3e+02f * fSlow4)];
		float fSlow43 = 0.0001f * float(iSlow42);
		int iSlow44 = itbl0_holeSIG0[int(2.3e+02f * fSlow4)];
		float fSlow45 = 0.0001f * float(iSlow44);
		int iSlow46 = itbl0_holeSIG0[int(204.0f * fSlow4)];
		float fSlow47 = 0.005f * float(iSlow46);
		int iSlow48 = itbl0_holeSIG0[int(54.0f * fSlow4)];
		float fSlow49 = 0.005f * float(iSlow48);
		int iSlow50 = itbl0_holeSIG0[int(125.0f * fSlow4)];
		float fSlow51 = 0.0001f * float(iSlow50);
		int iSlow52 = itbl0_holeSIG0[int(25.0f * fSlow4)];
		float fSlow53 = 0.0001f * float(iSlow52);
		int iSlow54 = itbl0_holeSIG0[int(155.0f * fSlow4)];
		float fSlow55 = 0.0001f * float(iSlow54);
		int iSlow56 = itbl0_holeSIG0[int(55.0f * fSlow4)];
		float fSlow57 = 0.0001f * float(iSlow56);
		int iSlow58 = itbl0_holeSIG0[int(185.0f * fSlow4)];
		float fSlow59 = 0.0001f * float(iSlow58);
		int iSlow60 = itbl0_holeSIG0[int(85.0f * fSlow4)];
		float fSlow61 = 0.0001f * float(iSlow60);
		int iSlow62 = itbl0_holeSIG0[int(215.0f * fSlow4)];
		float fSlow63 = 0.0001f * float(iSlow62);
		int iSlow64 = itbl0_holeSIG0[int(115.0f * fSlow4)];
		float fSlow65 = 0.0001f * float(iSlow64);
		int iSlow66 = itbl0_holeSIG0[int(245.0f * fSlow4)];
		float fSlow67 = 0.0001f * float(iSlow66);
		int iSlow68 = itbl0_holeSIG0[int(145.0f * fSlow4)];
		float fSlow69 = 0.0001f * float(iSlow68);
		int iSlow70 = itbl0_holeSIG0[int(134.0f * fSlow4)];
		float fSlow71 = 0.005f * float(iSlow70);
		float fSlow72 = (fSlow15 + -1.618034f) / fSlow14 + 1.0f;
		float fSlow73 = _hole_faustpower2_f(fSlow14);
		float fSlow74 = 2.0f * (1.0f - 1.0f / fSlow73);
		float fSlow75 = (fSlow15 + -0.618034f) / fSlow14 + 1.0f;
		float fSlow76 = 1.0f - fSlow7;
		float fSlow77 = 1.0f / fSlow11;
		float fSlow78 = (fSlow7 + -1.618034f) / fSlow6 + 1.0f;
		float fSlow79 = 2.0f * (1.0f - 1.0f / fSlow9);
		float fSlow80 = (fSlow7 + -0.618034f) / fSlow6 + 1.0f;
		float fSlow81 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider9)));
		float fSlow82 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider10)));
		float fSlow83 = 1.0f / (fSlow73 * fSlow16);
		float fSlow84 = 1.0f / (fSlow73 * fSlow18);
		float fSlow85 = 1.0f / ((fSlow7 + 1.618034f) / fSlow6 + 1.0f);
		float fSlow86 = (fSlow7 + -1.618034f) / fSlow6 + 1.0f;
		float fSlow87 = std::sin(fSlow0);
		int iSlow88 = itbl0_holeSIG0[int(34.0f * fSlow4)];
		float fSlow89 = 0.005f * float(iSlow88);
		int iSlow90 = itbl0_holeSIG0[int(2.4e+02f * fSlow4)];
		float fSlow91 = 0.0001f * float(iSlow90);
		int iSlow92 = itbl0_holeSIG0[int(1.9e+02f * fSlow4)];
		float fSlow93 = 0.0001f * float(iSlow92);
		int iSlow94 = itbl0_holeSIG0[int(175.0f * fSlow4)];
		float fSlow95 = 0.0001f * float(iSlow94);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec22[0] = fSlow24 * fRec23[1] + fSlow25 * fRec22[1];
			int iTemp0 = 1 - iVec0[1];
			fRec23[0] = fSlow25 * fRec23[1] + float(iTemp0) - fSlow24 * fRec22[1];
			float fTemp1 = fSlow22 * (fRec22[0] + 1.0f);
			float fTemp2 = fTemp1 + 3.500005f;
			float fTemp3 = std::floor(fTemp2);
			float fTemp4 = fTemp1 + (3.0f - fTemp3);
			float fTemp5 = 0.6496369f * fRec25[1];
			float fTemp6 = 0.6496369f * fRec37[1];
			float fTemp7 = 0.7602446f * fRec0[1] - 0.6496369f * fRec52[1];
			float fTemp8 = 0.6496369f * fRec53[1];
			float fTemp9 = 0.7602446f * fRec1[1];
			fVec1[IOTA0 & 16383] = 0.70710677f * fTemp7 + 0.70710677f * (fTemp8 - fTemp9);
			fRec55[0] = 0.9999f * (fRec55[1] + float(iSlow26 * iTemp0)) + fSlow27;
			float fTemp10 = fRec55[0] + -1.49999f;
			float fTemp11 = fVec1[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp10)))) & 16383];
			fVec2[0] = fTemp11;
			float fTemp12 = std::floor(fTemp10);
			fRec54[0] = fVec2[1] - (fTemp12 + (2.0f - fRec55[0])) * (fRec54[1] - fTemp11) / (fRec55[0] - fTemp12);
			fRec52[0] = fRec54[0];
			fVec3[IOTA0 & 16383] = 0.70710677f * fTemp7 + 0.70710677f * (fTemp9 - fTemp8);
			fRec57[0] = 0.9999f * (fRec57[1] + float(iSlow28 * iTemp0)) + fSlow29;
			float fTemp13 = fRec57[0] + -1.49999f;
			float fTemp14 = fVec3[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp13)))) & 16383];
			fVec4[0] = fTemp14;
			float fTemp15 = std::floor(fTemp13);
			fRec56[0] = fVec4[1] - (fTemp15 + (2.0f - fRec57[0])) * (fRec56[1] - fTemp14) / (fRec57[0] - fTemp15);
			fRec53[0] = fRec56[0];
			float fTemp16 = 0.7602446f * fRec52[1] + 0.6496369f * fRec0[1];
			float fTemp17 = 0.7602446f * fTemp16 - 0.6496369f * fRec49[1];
			float fTemp18 = 0.6496369f * fRec50[1];
			float fTemp19 = 0.7602446f * fRec53[1] + 0.6496369f * fRec1[1];
			float fTemp20 = 0.7602446f * fTemp19;
			fVec5[IOTA0 & 16383] = 0.70710677f * fTemp17 + 0.70710677f * (fTemp18 - fTemp20);
			fRec58[0] = 0.9999f * (fRec58[1] + float(iSlow30 * iTemp0)) + fSlow31;
			float fTemp21 = fRec58[0] + -1.49999f;
			float fTemp22 = fVec5[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp21)))) & 16383];
			fVec6[0] = fTemp22;
			float fTemp23 = std::floor(fTemp21);
			fRec51[0] = fVec6[1] + (fTemp22 - fRec51[1]) * (fTemp23 + (2.0f - fRec58[0])) / (fRec58[0] - fTemp23);
			fRec49[0] = fRec51[0];
			fVec7[IOTA0 & 16383] = 0.70710677f * fTemp17 + 0.70710677f * (fTemp20 - fTemp18);
			fRec60[0] = 0.9999f * (fRec60[1] + float(iSlow32 * iTemp0)) + fSlow33;
			float fTemp24 = fRec60[0] + -1.49999f;
			float fTemp25 = fVec7[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp24)))) & 16383];
			fVec8[0] = fTemp25;
			float fTemp26 = std::floor(fTemp24);
			fRec59[0] = fVec8[1] - (fTemp26 + (2.0f - fRec60[0])) * (fRec59[1] - fTemp25) / (fRec60[0] - fTemp26);
			fRec50[0] = fRec59[0];
			float fTemp27 = 0.7602446f * fRec49[1] + 0.6496369f * fTemp16;
			float fTemp28 = 0.7602446f * fTemp27 - 0.6496369f * fRec46[1];
			float fTemp29 = 0.6496369f * fRec47[1];
			float fTemp30 = 0.7602446f * fRec50[1] + 0.6496369f * fTemp19;
			float fTemp31 = 0.7602446f * fTemp30;
			fVec9[IOTA0 & 16383] = 0.70710677f * fTemp28 + 0.70710677f * (fTemp29 - fTemp31);
			fRec61[0] = 0.9999f * (fRec61[1] + float(iSlow34 * iTemp0)) + fSlow35;
			float fTemp32 = fRec61[0] + -1.49999f;
			float fTemp33 = fVec9[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp32)))) & 16383];
			fVec10[0] = fTemp33;
			float fTemp34 = std::floor(fTemp32);
			fRec48[0] = fVec10[1] - (fTemp34 + (2.0f - fRec61[0])) * (fRec48[1] - fTemp33) / (fRec61[0] - fTemp34);
			fRec46[0] = fRec48[0];
			fVec11[IOTA0 & 16383] = 0.70710677f * fTemp28 + 0.70710677f * (fTemp31 - fTemp29);
			fRec63[0] = 0.9999f * (fRec63[1] + float(iSlow36 * iTemp0)) + fSlow37;
			float fTemp35 = fRec63[0] + -1.49999f;
			float fTemp36 = fVec11[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp35)))) & 16383];
			fVec12[0] = fTemp36;
			float fTemp37 = std::floor(fTemp35);
			fRec62[0] = fVec12[1] - (fTemp37 + (2.0f - fRec63[0])) * (fRec62[1] - fTemp36) / (fRec63[0] - fTemp37);
			fRec47[0] = fRec62[0];
			float fTemp38 = 0.7602446f * fRec46[1] + 0.6496369f * fTemp27;
			float fTemp39 = 0.7602446f * fTemp38 - 0.6496369f * fRec43[1];
			float fTemp40 = 0.6496369f * fRec44[1];
			float fTemp41 = 0.7602446f * fRec47[1] + 0.6496369f * fTemp30;
			float fTemp42 = 0.7602446f * fTemp41;
			fVec13[IOTA0 & 16383] = 0.70710677f * fTemp39 + 0.70710677f * (fTemp40 - fTemp42);
			fRec64[0] = 0.9999f * (fRec64[1] + float(iSlow38 * iTemp0)) + fSlow39;
			float fTemp43 = fRec64[0] + -1.49999f;
			float fTemp44 = fVec13[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp43)))) & 16383];
			fVec14[0] = fTemp44;
			float fTemp45 = std::floor(fTemp43);
			fRec45[0] = fVec14[1] - (fTemp45 + (2.0f - fRec64[0])) * (fRec45[1] - fTemp44) / (fRec64[0] - fTemp45);
			fRec43[0] = fRec45[0];
			fVec15[IOTA0 & 16383] = 0.70710677f * fTemp39 + 0.70710677f * (fTemp42 - fTemp40);
			fRec66[0] = 0.9999f * (fRec66[1] + float(iSlow40 * iTemp0)) + fSlow41;
			float fTemp46 = fRec66[0] + -1.49999f;
			float fTemp47 = fVec15[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp46)))) & 16383];
			fVec16[0] = fTemp47;
			float fTemp48 = std::floor(fTemp46);
			fRec65[0] = fVec16[1] - (fTemp48 + (2.0f - fRec66[0])) * (fRec65[1] - fTemp47) / (fRec66[0] - fTemp48);
			fRec44[0] = fRec65[0];
			float fTemp49 = 0.7602446f * fRec43[1] + 0.6496369f * fTemp38;
			float fTemp50 = 0.7602446f * fTemp49 - 0.6496369f * fRec40[1];
			float fTemp51 = 0.6496369f * fRec41[1];
			float fTemp52 = 0.7602446f * fRec44[1] + 0.6496369f * fTemp41;
			float fTemp53 = 0.7602446f * fTemp52;
			fVec17[IOTA0 & 16383] = 0.70710677f * fTemp50 + 0.70710677f * (fTemp51 - fTemp53);
			fRec67[0] = 0.9999f * (fRec67[1] + float(iSlow42 * iTemp0)) + fSlow43;
			float fTemp54 = fRec67[0] + -1.49999f;
			float fTemp55 = fVec17[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp54)))) & 16383];
			fVec18[0] = fTemp55;
			float fTemp56 = std::floor(fTemp54);
			fRec42[0] = fVec18[1] - (fTemp56 + (2.0f - fRec67[0])) * (fRec42[1] - fTemp55) / (fRec67[0] - fTemp56);
			fRec40[0] = fRec42[0];
			fVec19[IOTA0 & 16383] = 0.70710677f * fTemp50 + 0.70710677f * (fTemp53 - fTemp51);
			fRec69[0] = 0.9999f * (fRec69[1] + float(iSlow44 * iTemp0)) + fSlow45;
			float fTemp57 = fRec69[0] + -1.49999f;
			float fTemp58 = fVec19[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp57)))) & 16383];
			fVec20[0] = fTemp58;
			float fTemp59 = std::floor(fTemp57);
			fRec68[0] = fVec20[1] - (fTemp59 + (2.0f - fRec69[0])) * (fRec68[1] - fTemp58) / (fRec69[0] - fTemp59);
			fRec41[0] = fRec68[0];
			float fTemp60 = 0.7602446f * fRec41[1] + 0.6496369f * fTemp52;
			fVec21[IOTA0 & 1023] = fTemp60;
			float fTemp61 = fSlow22 * (fRec23[0] + -1.0f);
			float fTemp62 = 3.500005f - fTemp61;
			int iTemp63 = int(fTemp62);
			float fTemp64 = fTemp61 + std::floor(fTemp62);
			float fTemp65 = 5.0f - fTemp64;
			float fTemp66 = 4.0f - fTemp64;
			float fTemp67 = 3.0f - fTemp64;
			float fTemp68 = 2.0f - fTemp64;
			fVec22[IOTA0 & 16383] = ((0.25f * fVec21[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp63 + 2))) & 1023] * fTemp65 * fTemp66 + fTemp67 * (0.041666668f * fVec21[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp63))) & 1023] * fTemp66 - 0.16666667f * fVec21[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp63 + 1))) & 1023] * fTemp65)) * fTemp68 - 0.16666667f * fVec21[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp63 + 3))) & 1023] * fTemp67 * fTemp65 * fTemp66) * (1.0f - fTemp64) + 0.041666668f * fVec21[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp63 + 4))) & 1023] * fTemp67 * fTemp68 * fTemp65 * fTemp66;
			fRec70[0] = 0.995f * (fRec70[1] + float(iSlow46 * iTemp0)) + fSlow47;
			float fTemp69 = fRec70[0] + -1.49999f;
			float fTemp70 = fVec22[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp69)))) & 16383];
			fVec23[0] = fTemp70;
			float fTemp71 = std::floor(fTemp69);
			fRec39[0] = fVec23[1] + (fTemp70 - fRec39[1]) * (fTemp71 + (2.0f - fRec70[0])) / (fRec70[0] - fTemp71);
			float fTemp72 = 0.7602446f * fRec39[0];
			float fTemp73 = 0.7602446f * fRec40[1] + 0.6496369f * fTemp49;
			fVec24[IOTA0 & 1023] = fTemp73;
			float fTemp74 = fSlow22 * (fRec23[0] + 1.0f);
			float fTemp75 = fTemp74 + 3.500005f;
			int iTemp76 = int(fTemp75);
			int iTemp77 = std::min<int>(512, std::max<int>(0, iTemp76));
			float fTemp78 = std::floor(fTemp75);
			float fTemp79 = fTemp74 + (4.0f - fTemp78);
			float fTemp80 = fTemp74 + (5.0f - fTemp78);
			int iTemp81 = std::min<int>(512, std::max<int>(0, iTemp76 + 1));
			float fTemp82 = fTemp74 + (3.0f - fTemp78);
			int iTemp83 = std::min<int>(512, std::max<int>(0, iTemp76 + 2));
			float fTemp84 = fTemp74 + (2.0f - fTemp78);
			int iTemp85 = std::min<int>(512, std::max<int>(0, iTemp76 + 3));
			float fTemp86 = fTemp74 + (1.0f - fTemp78);
			int iTemp87 = std::min<int>(512, std::max<int>(0, iTemp76 + 4));
			fVec25[IOTA0 & 16383] = (((0.041666668f * fVec24[(IOTA0 - iTemp77) & 1023] * fTemp79 - 0.16666667f * fTemp80 * fVec24[(IOTA0 - iTemp81) & 1023]) * fTemp82 + 0.25f * fVec24[(IOTA0 - iTemp83) & 1023] * fTemp80 * fTemp79) * fTemp84 - 0.16666667f * fVec24[(IOTA0 - iTemp85) & 1023] * fTemp80 * fTemp79 * fTemp82) * fTemp86 + 0.041666668f * fVec24[(IOTA0 - iTemp87) & 1023] * fTemp80 * fTemp79 * fTemp82 * fTemp84;
			fRec72[0] = 0.995f * (fRec72[1] + float(iSlow48 * iTemp0)) + fSlow49;
			float fTemp88 = fRec72[0] + -1.49999f;
			float fTemp89 = fVec25[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp88)))) & 16383];
			fVec26[0] = fTemp89;
			float fTemp90 = std::floor(fTemp88);
			fRec71[0] = fVec26[1] - (fTemp90 + (2.0f - fRec72[0])) * (fRec71[1] - fTemp89) / (fRec72[0] - fTemp90);
			float fTemp91 = 0.7602446f * fRec71[0] - 0.6496369f * fRec36[1];
			fVec27[IOTA0 & 16383] = 0.70710677f * (fTemp6 - fTemp72) + 0.70710677f * fTemp91;
			fRec73[0] = 0.9999f * (fRec73[1] + float(iSlow50 * iTemp0)) + fSlow51;
			float fTemp92 = fRec73[0] + -1.49999f;
			float fTemp93 = fVec27[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp92)))) & 16383];
			fVec28[0] = fTemp93;
			float fTemp94 = std::floor(fTemp92);
			fRec38[0] = fVec28[1] - (fTemp94 + (2.0f - fRec73[0])) * (fRec38[1] - fTemp93) / (fRec73[0] - fTemp94);
			fRec36[0] = fRec38[0];
			fVec29[IOTA0 & 16383] = 0.70710677f * fTemp91 + 0.70710677f * (fTemp72 - fTemp6);
			fRec75[0] = 0.9999f * (fRec75[1] + float(iSlow52 * iTemp0)) + fSlow53;
			float fTemp95 = fRec75[0] + -1.49999f;
			float fTemp96 = fVec29[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp95)))) & 16383];
			fVec30[0] = fTemp96;
			float fTemp97 = std::floor(fTemp95);
			fRec74[0] = fVec30[1] - (fTemp97 + (2.0f - fRec75[0])) * (fRec74[1] - fTemp96) / (fRec75[0] - fTemp97);
			fRec37[0] = fRec74[0];
			float fTemp98 = 0.7602446f * fRec36[1] + 0.6496369f * fRec71[0];
			float fTemp99 = 0.7602446f * fTemp98 - 0.6496369f * fRec33[1];
			float fTemp100 = 0.6496369f * fRec34[1];
			float fTemp101 = 0.7602446f * fRec37[1] + 0.6496369f * fRec39[0];
			float fTemp102 = 0.7602446f * fTemp101;
			fVec31[IOTA0 & 16383] = 0.70710677f * fTemp99 + 0.70710677f * (fTemp100 - fTemp102);
			fRec76[0] = 0.9999f * (fRec76[1] + float(iSlow54 * iTemp0)) + fSlow55;
			float fTemp103 = fRec76[0] + -1.49999f;
			float fTemp104 = fVec31[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp103)))) & 16383];
			fVec32[0] = fTemp104;
			float fTemp105 = std::floor(fTemp103);
			fRec35[0] = fVec32[1] - (fTemp105 + (2.0f - fRec76[0])) * (fRec35[1] - fTemp104) / (fRec76[0] - fTemp105);
			fRec33[0] = fRec35[0];
			fVec33[IOTA0 & 16383] = 0.70710677f * fTemp99 + 0.70710677f * (fTemp102 - fTemp100);
			fRec78[0] = 0.9999f * (fRec78[1] + float(iSlow56 * iTemp0)) + fSlow57;
			float fTemp106 = fRec78[0] + -1.49999f;
			int iTemp107 = std::min<int>(8192, std::max<int>(0, int(fTemp106)));
			float fTemp108 = fVec33[(IOTA0 - iTemp107) & 16383];
			fVec34[0] = fTemp108;
			float fTemp109 = std::floor(fTemp106);
			float fTemp110 = fTemp109 + (2.0f - fRec78[0]);
			float fTemp111 = fRec78[0] - fTemp109;
			fRec77[0] = fVec34[1] - fTemp110 * (fRec77[1] - fTemp108) / fTemp111;
			fRec34[0] = fRec77[0];
			float fTemp112 = 0.7602446f * fRec33[1] + 0.6496369f * fTemp98;
			float fTemp113 = 0.7602446f * fTemp112 - 0.6496369f * fRec30[1];
			float fTemp114 = 0.6496369f * fRec31[1];
			float fTemp115 = 0.7602446f * fRec34[1] + 0.6496369f * fTemp101;
			float fTemp116 = 0.7602446f * fTemp115;
			fVec35[IOTA0 & 16383] = 0.70710677f * fTemp113 + 0.70710677f * (fTemp114 - fTemp116);
			fRec79[0] = 0.9999f * (fRec79[1] + float(iSlow58 * iTemp0)) + fSlow59;
			float fTemp117 = fRec79[0] + -1.49999f;
			float fTemp118 = fVec35[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp117)))) & 16383];
			fVec36[0] = fTemp118;
			float fTemp119 = std::floor(fTemp117);
			fRec32[0] = fVec36[1] - (fTemp119 + (2.0f - fRec79[0])) * (fRec32[1] - fTemp118) / (fRec79[0] - fTemp119);
			fRec30[0] = fRec32[0];
			fVec37[IOTA0 & 16383] = 0.70710677f * fTemp113 + 0.70710677f * (fTemp116 - fTemp114);
			fRec81[0] = 0.9999f * (fRec81[1] + float(iSlow60 * iTemp0)) + fSlow61;
			float fTemp120 = fRec81[0] + -1.49999f;
			int iTemp121 = std::min<int>(8192, std::max<int>(0, int(fTemp120)));
			float fTemp122 = fVec37[(IOTA0 - iTemp121) & 16383];
			fVec38[0] = fTemp122;
			float fTemp123 = std::floor(fTemp120);
			float fTemp124 = fTemp123 + (2.0f - fRec81[0]);
			float fTemp125 = fRec81[0] - fTemp123;
			fRec80[0] = fVec38[1] - fTemp124 * (fRec80[1] - fTemp122) / fTemp125;
			fRec31[0] = fRec80[0];
			float fTemp126 = 0.7602446f * fRec30[1] + 0.6496369f * fTemp112;
			float fTemp127 = 0.7602446f * fTemp126 - 0.6496369f * fRec27[1];
			float fTemp128 = 0.6496369f * fRec28[1];
			float fTemp129 = 0.7602446f * fRec31[1] + 0.6496369f * fTemp115;
			float fTemp130 = 0.7602446f * fTemp129;
			fVec39[IOTA0 & 16383] = 0.70710677f * fTemp127 + 0.70710677f * (fTemp128 - fTemp130);
			fRec82[0] = 0.9999f * (fRec82[1] + float(iSlow62 * iTemp0)) + fSlow63;
			float fTemp131 = fRec82[0] + -1.49999f;
			int iTemp132 = std::min<int>(8192, std::max<int>(0, int(fTemp131)));
			float fTemp133 = fVec39[(IOTA0 - iTemp132) & 16383];
			fVec40[0] = fTemp133;
			float fTemp134 = std::floor(fTemp131);
			float fTemp135 = fTemp134 + (2.0f - fRec82[0]);
			float fTemp136 = fRec82[0] - fTemp134;
			fRec29[0] = fVec40[1] - fTemp135 * (fRec29[1] - fTemp133) / fTemp136;
			fRec27[0] = fRec29[0];
			fVec41[IOTA0 & 16383] = 0.70710677f * fTemp127 + 0.70710677f * (fTemp130 - fTemp128);
			fRec84[0] = 0.9999f * (fRec84[1] + float(iSlow64 * iTemp0)) + fSlow65;
			float fTemp137 = fRec84[0] + -1.49999f;
			int iTemp138 = std::min<int>(8192, std::max<int>(0, int(fTemp137)));
			float fTemp139 = fVec41[(IOTA0 - iTemp138) & 16383];
			fVec42[0] = fTemp139;
			float fTemp140 = std::floor(fTemp137);
			float fTemp141 = fTemp140 + (2.0f - fRec84[0]);
			float fTemp142 = fRec84[0] - fTemp140;
			fRec83[0] = fVec42[1] - fTemp141 * (fRec83[1] - fTemp139) / fTemp142;
			fRec28[0] = fRec83[0];
			float fTemp143 = 0.7602446f * fRec28[1] + 0.6496369f * fTemp129;
			float fTemp144 = 0.7602446f * fTemp143;
			float fTemp145 = 0.7602446f * fRec27[1] + 0.6496369f * fTemp126;
			float fTemp146 = 0.7602446f * fTemp145 - 0.6496369f * fRec24[1];
			fVec43[IOTA0 & 16383] = 0.70710677f * (fTemp5 - fTemp144) + 0.70710677f * fTemp146;
			fRec85[0] = 0.9999f * (fRec85[1] + float(iSlow66 * iTemp0)) + fSlow67;
			float fTemp147 = fRec85[0] + -1.49999f;
			float fTemp148 = fVec43[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp147)))) & 16383];
			fVec44[0] = fTemp148;
			float fTemp149 = std::floor(fTemp147);
			fRec26[0] = fVec44[1] - (fTemp149 + (2.0f - fRec85[0])) * (fRec26[1] - fTemp148) / (fRec85[0] - fTemp149);
			fRec24[0] = fRec26[0];
			fVec45[IOTA0 & 16383] = 0.70710677f * fTemp146 + 0.70710677f * (fTemp144 - fTemp5);
			fRec87[0] = 0.9999f * (fRec87[1] + float(iSlow68 * iTemp0)) + fSlow69;
			float fTemp150 = fRec87[0] + -1.49999f;
			int iTemp151 = std::min<int>(8192, std::max<int>(0, int(fTemp150)));
			float fTemp152 = fVec45[(IOTA0 - iTemp151) & 16383];
			fVec46[0] = fTemp152;
			float fTemp153 = std::floor(fTemp150);
			float fTemp154 = fTemp153 + (2.0f - fRec87[0]);
			float fTemp155 = fRec87[0] - fTemp153;
			fRec86[0] = fVec46[1] - fTemp154 * (fRec86[1] - fTemp152) / fTemp155;
			fRec25[0] = fRec86[0];
			float fTemp156 = 0.7602446f * fRec24[1] + 0.6496369f * fTemp145;
			fVec47[IOTA0 & 16383] = fTemp156;
			int iTemp157 = int(fTemp2);
			int iTemp158 = std::max<int>(0, iTemp157);
			float fTemp159 = fTemp1 + (4.0f - fTemp3);
			float fTemp160 = fTemp1 + (5.0f - fTemp3);
			int iTemp161 = std::max<int>(0, iTemp157 + 1);
			int iTemp162 = std::max<int>(0, iTemp157 + 2);
			float fTemp163 = fTemp1 + (2.0f - fTemp3);
			int iTemp164 = std::max<int>(0, iTemp157 + 3);
			float fTemp165 = fTemp1 + (1.0f - fTemp3);
			int iTemp166 = std::max<int>(0, iTemp157 + 4);
			fVec48[IOTA0 & 16383] = ((fTemp4 * (0.041666668f * fVec47[(IOTA0 - std::min<int>(8192, iTemp158)) & 16383] * fTemp159 - 0.16666667f * fTemp160 * fVec47[(IOTA0 - std::min<int>(8192, iTemp161)) & 16383]) + 0.25f * fTemp160 * fTemp159 * fVec47[(IOTA0 - std::min<int>(8192, iTemp162)) & 16383]) * fTemp163 - 0.16666667f * fVec47[(IOTA0 - std::min<int>(8192, iTemp164)) & 16383] * fTemp160 * fTemp159 * fTemp4) * fTemp165 + 0.041666668f * fVec47[(IOTA0 - std::min<int>(8192, iTemp166)) & 16383] * fTemp160 * fTemp159 * fTemp4 * fTemp163;
			fRec88[0] = 0.995f * (fRec88[1] + float(iSlow70 * iTemp0)) + fSlow71;
			float fTemp167 = fRec88[0] + -1.49999f;
			float fTemp168 = fVec48[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp167)))) & 16383];
			fVec49[0] = fTemp168;
			float fTemp169 = std::floor(fTemp167);
			fRec21[0] = fVec49[1] - (fTemp169 + (2.0f - fRec88[0])) * (fRec21[1] - fTemp168) / (fRec88[0] - fTemp169);
			fRec20[0] = -(fSlow20 * (fSlow21 * fRec20[1] - (fRec21[0] + fRec21[1])));
			fRec19[0] = fRec20[0] - fSlow19 * (fSlow72 * fRec19[2] + fSlow74 * fRec19[1]);
			fRec18[0] = fSlow19 * (fRec19[0] + 2.0f * fRec19[1] + fRec19[2]) - fSlow17 * (fSlow74 * fRec18[1] + fSlow75 * fRec18[2]);
			float fTemp170 = fSlow17 * (fRec18[0] + 2.0f * fRec18[1] + fRec18[2]);
			fVec50[0] = fTemp170;
			fRec17[0] = fSlow13 * (fSlow7 * (fTemp170 - fVec50[1]) - fSlow76 * fRec17[1]);
			fRec16[0] = fRec17[0] - fSlow77 * (fSlow78 * fRec16[2] + fSlow79 * fRec16[1]);
			fRec15[0] = fSlow12 * (fRec16[2] + (fRec16[0] - 2.0f * fRec16[1])) - fSlow8 * (fSlow80 * fRec15[2] + fSlow79 * fRec15[1]);
			fRec91[0] = -(fSlow13 * (fSlow76 * fRec91[1] - (fVec50[1] + fTemp170)));
			fRec90[0] = fRec91[0] - fSlow77 * (fSlow78 * fRec90[2] + fSlow79 * fRec90[1]);
			fRec89[0] = fSlow77 * (fRec90[2] + fRec90[0] + 2.0f * fRec90[1]) - fSlow8 * (fSlow80 * fRec89[2] + fSlow79 * fRec89[1]);
			fRec95[0] = -(fSlow20 * (fSlow21 * fRec95[1] - fSlow15 * (fRec21[0] - fRec21[1])));
			fRec94[0] = fRec95[0] - fSlow19 * (fSlow72 * fRec94[2] + fSlow74 * fRec94[1]);
			fRec93[0] = fSlow84 * (fRec94[2] + (fRec94[0] - 2.0f * fRec94[1])) - fSlow17 * (fSlow74 * fRec93[1] + fSlow75 * fRec93[2]);
			float fTemp171 = fSlow79 * fRec92[1];
			fRec92[0] = fSlow83 * (fRec93[0] - 2.0f * fRec93[1] + fRec93[2]) - fSlow85 * (fSlow86 * fRec92[2] + fTemp171);
			float fTemp172 = fSlow5 * (fSlow8 * (fSlow10 * (fRec15[2] + (fRec15[0] - 2.0f * fRec15[1])) + fSlow81 * (fRec89[2] + fRec89[0] + 2.0f * fRec89[1])) + fSlow82 * (fRec92[2] + fSlow85 * (fTemp171 + fSlow86 * fRec92[0]))) + float(input0[i0]);
			fVec51[IOTA0 & 1023] = fTemp172;
			fRec14[0] = fSlow3 * ((((0.041666668f * fVec51[(IOTA0 - std::min<int>(512, iTemp158)) & 1023] * fTemp159 - 0.16666667f * fVec51[(IOTA0 - std::min<int>(512, iTemp161)) & 1023] * fTemp160) * fTemp4 + 0.25f * fVec51[(IOTA0 - std::min<int>(512, iTemp162)) & 1023] * fTemp160 * fTemp159) * fTemp163 - 0.16666667f * fVec51[(IOTA0 - std::min<int>(512, iTemp164)) & 1023] * fTemp160 * fTemp159 * fTemp4) * fTemp165 + 0.041666668f * fVec51[(IOTA0 - std::min<int>(512, iTemp166)) & 1023] * fTemp160 * fTemp159 * fTemp4 * fTemp163) + fSlow2 * fRec14[1];
			float fTemp173 = fSlow1 * fRec14[0] - fSlow87 * fRec11[1];
			float fTemp174 = fSlow87 * fRec12[1];
			float fTemp175 = 0.7602446f * fRec25[1] + 0.6496369f * fTemp143;
			fVec52[IOTA0 & 16383] = fTemp175;
			float fTemp176 = fSlow22 * (fRec22[0] + -1.0f);
			float fTemp177 = 3.500005f - fTemp176;
			int iTemp178 = int(fTemp177);
			float fTemp179 = fTemp176 + std::floor(fTemp177);
			float fTemp180 = 4.0f - fTemp179;
			float fTemp181 = 5.0f - fTemp179;
			float fTemp182 = 3.0f - fTemp179;
			float fTemp183 = 2.0f - fTemp179;
			fVec53[IOTA0 & 16383] = (((0.041666668f * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp178))) & 16383] * fTemp180 - 0.16666667f * fTemp181 * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp178 + 1))) & 16383]) * fTemp182 + 0.25f * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp178 + 2))) & 16383] * fTemp181 * fTemp180) * fTemp183 - 0.16666667f * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp178 + 3))) & 16383] * fTemp181 * fTemp180 * fTemp182) * (1.0f - fTemp179) + 0.041666668f * fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp178 + 4))) & 16383] * fTemp181 * fTemp180 * fTemp182 * fTemp183;
			fRec102[0] = 0.995f * (fRec102[1] + float(iSlow88 * iTemp0)) + fSlow89;
			float fTemp184 = fRec102[0] + -1.49999f;
			float fTemp185 = fVec53[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp184)))) & 16383];
			fVec54[0] = fTemp185;
			float fTemp186 = std::floor(fTemp184);
			fRec101[0] = fVec54[1] - (fTemp186 + (2.0f - fRec102[0])) * (fRec101[1] - fTemp185) / (fRec102[0] - fTemp186);
			fRec100[0] = -(fSlow20 * (fSlow21 * fRec100[1] - fSlow15 * (fRec101[0] - fRec101[1])));
			fRec99[0] = fRec100[0] - fSlow19 * (fSlow72 * fRec99[2] + fSlow74 * fRec99[1]);
			fRec98[0] = fSlow84 * (fRec99[2] + (fRec99[0] - 2.0f * fRec99[1])) - fSlow17 * (fSlow75 * fRec98[2] + fSlow74 * fRec98[1]);
			float fTemp187 = fSlow79 * fRec97[1];
			fRec97[0] = fSlow83 * (fRec98[2] + (fRec98[0] - 2.0f * fRec98[1])) - fSlow85 * (fSlow86 * fRec97[2] + fTemp187);
			fRec108[0] = -(fSlow20 * (fSlow21 * fRec108[1] - (fRec101[0] + fRec101[1])));
			fRec107[0] = fRec108[0] - fSlow19 * (fSlow72 * fRec107[2] + fSlow74 * fRec107[1]);
			fRec106[0] = fSlow19 * (fRec107[2] + fRec107[0] + 2.0f * fRec107[1]) - fSlow17 * (fSlow75 * fRec106[2] + fSlow74 * fRec106[1]);
			float fTemp188 = fSlow17 * (fRec106[2] + fRec106[0] + 2.0f * fRec106[1]);
			fVec55[0] = fTemp188;
			fRec105[0] = -(fSlow13 * (fSlow76 * fRec105[1] - (fTemp188 + fVec55[1])));
			fRec104[0] = fRec105[0] - fSlow77 * (fSlow78 * fRec104[2] + fSlow79 * fRec104[1]);
			fRec103[0] = fSlow77 * (fRec104[2] + fRec104[0] + 2.0f * fRec104[1]) - fSlow8 * (fSlow80 * fRec103[2] + fSlow79 * fRec103[1]);
			fRec111[0] = -(fSlow13 * (fSlow76 * fRec111[1] - fSlow7 * (fTemp188 - fVec55[1])));
			fRec110[0] = fRec111[0] - fSlow77 * (fSlow78 * fRec110[2] + fSlow79 * fRec110[1]);
			fRec109[0] = fSlow12 * (fRec110[2] + (fRec110[0] - 2.0f * fRec110[1])) - fSlow8 * (fSlow80 * fRec109[2] + fSlow79 * fRec109[1]);
			float fTemp189 = fSlow5 * (fSlow82 * (fSlow85 * (fSlow86 * fRec97[0] + fTemp187) + fRec97[2]) + fSlow8 * (fSlow81 * (fRec103[2] + fRec103[0] + 2.0f * fRec103[1]) + fSlow10 * (fRec109[2] + (fRec109[0] - 2.0f * fRec109[1])))) + float(input1[i0]);
			fVec56[IOTA0 & 1023] = fTemp189;
			fRec96[0] = fSlow3 * ((((0.041666668f * fVec56[(IOTA0 - iTemp77) & 1023] * fTemp79 - 0.16666667f * fVec56[(IOTA0 - iTemp81) & 1023] * fTemp80) * fTemp82 + 0.25f * fVec56[(IOTA0 - iTemp83) & 1023] * fTemp80 * fTemp79) * fTemp84 - 0.16666667f * fVec56[(IOTA0 - iTemp85) & 1023] * fTemp80 * fTemp79 * fTemp82) * fTemp86 + 0.041666668f * fVec56[(IOTA0 - iTemp87) & 1023] * fTemp80 * fTemp79 * fTemp82 * fTemp84) + fSlow2 * fRec96[1];
			float fTemp190 = fSlow1 * fRec96[0];
			fVec57[IOTA0 & 16383] = 0.70710677f * fTemp173 + 0.70710677f * (fTemp174 - fTemp190);
			float fTemp191 = fVec57[(IOTA0 - iTemp107) & 16383];
			fVec58[0] = fTemp191;
			fRec13[0] = fVec58[1] + (fTemp191 - fRec13[1]) * fTemp110 / fTemp111;
			fRec11[0] = fRec13[0];
			fVec59[IOTA0 & 16383] = 0.70710677f * fTemp173 + 0.70710677f * (fTemp190 - fTemp174);
			fRec113[0] = 0.9999f * (fRec113[1] + float(iSlow90 * iTemp0)) + fSlow91;
			float fTemp192 = fRec113[0] + -1.49999f;
			float fTemp193 = fVec59[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp192)))) & 16383];
			fVec60[0] = fTemp193;
			float fTemp194 = std::floor(fTemp192);
			fRec112[0] = fVec60[1] - (fTemp194 + (2.0f - fRec113[0])) * (fRec112[1] - fTemp193) / (fRec113[0] - fTemp194);
			fRec12[0] = fRec112[0];
			float fTemp195 = fSlow1 * fRec11[1] + fSlow87 * fRec14[0];
			float fTemp196 = fSlow1 * fTemp195 - fSlow87 * fRec8[1];
			float fTemp197 = fSlow87 * fRec9[1];
			float fTemp198 = fSlow1 * fRec12[1] + fSlow87 * fRec96[0];
			float fTemp199 = fSlow1 * fTemp198;
			fVec61[IOTA0 & 16383] = 0.70710677f * fTemp196 + 0.70710677f * (fTemp197 - fTemp199);
			float fTemp200 = fVec61[(IOTA0 - iTemp132) & 16383];
			fVec62[0] = fTemp200;
			fRec10[0] = fVec62[1] + (fTemp200 - fRec10[1]) * fTemp135 / fTemp136;
			fRec8[0] = fRec10[0];
			fVec63[IOTA0 & 16383] = 0.70710677f * fTemp196 + 0.70710677f * (fTemp199 - fTemp197);
			float fTemp201 = fVec63[(IOTA0 - iTemp121) & 16383];
			fVec64[0] = fTemp201;
			fRec114[0] = fVec64[1] - (fRec114[1] - fTemp201) * fTemp124 / fTemp125;
			fRec9[0] = fRec114[0];
			float fTemp202 = fSlow1 * fRec8[1] + fSlow87 * fTemp195;
			float fTemp203 = fSlow1 * fTemp202 - fSlow87 * fRec5[1];
			float fTemp204 = fSlow87 * fRec6[1];
			float fTemp205 = fSlow1 * fRec9[1] + fSlow87 * fTemp198;
			float fTemp206 = fSlow1 * fTemp205;
			fVec65[IOTA0 & 16383] = 0.70710677f * fTemp203 + 0.70710677f * (fTemp204 - fTemp206);
			float fTemp207 = fVec65[(IOTA0 - iTemp138) & 16383];
			fVec66[0] = fTemp207;
			fRec7[0] = fVec66[1] + (fTemp207 - fRec7[1]) * fTemp141 / fTemp142;
			fRec5[0] = fRec7[0];
			fVec67[IOTA0 & 16383] = 0.70710677f * fTemp203 + 0.70710677f * (fTemp206 - fTemp204);
			fRec116[0] = 0.9999f * (fRec116[1] + float(iSlow92 * iTemp0)) + fSlow93;
			float fTemp208 = fRec116[0] + -1.49999f;
			float fTemp209 = fVec67[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp208)))) & 16383];
			fVec68[0] = fTemp209;
			float fTemp210 = std::floor(fTemp208);
			fRec115[0] = fVec68[1] + (fTemp209 - fRec115[1]) * (fTemp210 + (2.0f - fRec116[0])) / (fRec116[0] - fTemp210);
			fRec6[0] = fRec115[0];
			float fTemp211 = fSlow1 * fRec5[1] + fSlow87 * fTemp202;
			float fTemp212 = fSlow1 * fTemp211 - fSlow87 * fRec2[1];
			float fTemp213 = fSlow87 * fRec3[1];
			float fTemp214 = fSlow1 * fRec6[1] + fSlow87 * fTemp205;
			float fTemp215 = fSlow1 * fTemp214;
			fVec69[IOTA0 & 16383] = 0.70710677f * fTemp212 + 0.70710677f * (fTemp213 - fTemp215);
			fRec117[0] = 0.9999f * (fRec117[1] + float(iSlow94 * iTemp0)) + fSlow95;
			float fTemp216 = fRec117[0] + -1.49999f;
			float fTemp217 = fVec69[(IOTA0 - std::min<int>(8192, std::max<int>(0, int(fTemp216)))) & 16383];
			fVec70[0] = fTemp217;
			float fTemp218 = std::floor(fTemp216);
			fRec4[0] = fVec70[1] + (fTemp217 - fRec4[1]) * (fTemp218 + (2.0f - fRec117[0])) / (fRec117[0] - fTemp218);
			fRec2[0] = fRec4[0];
			fVec71[IOTA0 & 16383] = 0.70710677f * fTemp212 + 0.70710677f * (fTemp215 - fTemp213);
			float fTemp219 = fVec71[(IOTA0 - iTemp151) & 16383];
			fVec72[0] = fTemp219;
			fRec118[0] = fVec72[1] - (fRec118[1] - fTemp219) * fTemp154 / fTemp155;
			fRec3[0] = fRec118[0];
			fRec0[0] = fSlow1 * fRec2[1] + fSlow87 * fTemp211;
			fRec1[0] = fSlow1 * fRec3[1] + fSlow87 * fTemp214;
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			output1[i0] = FAUSTFLOAT(fRec1[0]);
			iVec0[1] = iVec0[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			IOTA0 = IOTA0 + 1;
			fRec55[1] = fRec55[0];
			fVec2[1] = fVec2[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec57[1] = fRec57[0];
			fVec4[1] = fVec4[0];
			fRec56[1] = fRec56[0];
			fRec53[1] = fRec53[0];
			fRec58[1] = fRec58[0];
			fVec6[1] = fVec6[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec60[1] = fRec60[0];
			fVec8[1] = fVec8[0];
			fRec59[1] = fRec59[0];
			fRec50[1] = fRec50[0];
			fRec61[1] = fRec61[0];
			fVec10[1] = fVec10[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec63[1] = fRec63[0];
			fVec12[1] = fVec12[0];
			fRec62[1] = fRec62[0];
			fRec47[1] = fRec47[0];
			fRec64[1] = fRec64[0];
			fVec14[1] = fVec14[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec66[1] = fRec66[0];
			fVec16[1] = fVec16[0];
			fRec65[1] = fRec65[0];
			fRec44[1] = fRec44[0];
			fRec67[1] = fRec67[0];
			fVec18[1] = fVec18[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec69[1] = fRec69[0];
			fVec20[1] = fVec20[0];
			fRec68[1] = fRec68[0];
			fRec41[1] = fRec41[0];
			fRec70[1] = fRec70[0];
			fVec23[1] = fVec23[0];
			fRec39[1] = fRec39[0];
			fRec72[1] = fRec72[0];
			fVec26[1] = fVec26[0];
			fRec71[1] = fRec71[0];
			fRec73[1] = fRec73[0];
			fVec28[1] = fVec28[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec75[1] = fRec75[0];
			fVec30[1] = fVec30[0];
			fRec74[1] = fRec74[0];
			fRec37[1] = fRec37[0];
			fRec76[1] = fRec76[0];
			fVec32[1] = fVec32[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec78[1] = fRec78[0];
			fVec34[1] = fVec34[0];
			fRec77[1] = fRec77[0];
			fRec34[1] = fRec34[0];
			fRec79[1] = fRec79[0];
			fVec36[1] = fVec36[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec81[1] = fRec81[0];
			fVec38[1] = fVec38[0];
			fRec80[1] = fRec80[0];
			fRec31[1] = fRec31[0];
			fRec82[1] = fRec82[0];
			fVec40[1] = fVec40[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec84[1] = fRec84[0];
			fVec42[1] = fVec42[0];
			fRec83[1] = fRec83[0];
			fRec28[1] = fRec28[0];
			fRec85[1] = fRec85[0];
			fVec44[1] = fVec44[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec87[1] = fRec87[0];
			fVec46[1] = fVec46[0];
			fRec86[1] = fRec86[0];
			fRec25[1] = fRec25[0];
			fRec88[1] = fRec88[0];
			fVec49[1] = fVec49[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fVec50[1] = fVec50[0];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec91[1] = fRec91[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			fRec95[1] = fRec95[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec14[1] = fRec14[0];
			fRec102[1] = fRec102[0];
			fVec54[1] = fVec54[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec108[1] = fRec108[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fVec55[1] = fVec55[0];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec111[1] = fRec111[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec96[1] = fRec96[0];
			fVec58[1] = fVec58[0];
			fRec13[1] = fRec13[0];
			fRec11[1] = fRec11[0];
			fRec113[1] = fRec113[0];
			fVec60[1] = fVec60[0];
			fRec112[1] = fRec112[0];
			fRec12[1] = fRec12[0];
			fVec62[1] = fVec62[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fVec64[1] = fVec64[0];
			fRec114[1] = fRec114[0];
			fRec9[1] = fRec9[0];
			fVec66[1] = fVec66[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec116[1] = fRec116[0];
			fVec68[1] = fVec68[0];
			fRec115[1] = fRec115[0];
			fRec6[1] = fRec6[0];
			fRec117[1] = fRec117[0];
			fVec70[1] = fVec70[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fVec72[1] = fVec72[0];
			fRec118[1] = fRec118[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "hole.dsp"
	#define FAUST_CLASS_NAME "_hole"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _hole -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 11
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[0] Mix/earlyDiff", fHslider0, 0.70710677f, 0.0f, 0.99f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[0] Mix/size", fHslider2, 1.0f, 0.5f, 3.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[0] Mix/t60", fHslider3, 1.0f, 0.1f, 6e+01f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[0] Mix/damp", fHslider1, 0.0f, 0.0f, 0.999f, 0.0001f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[1] EQ/lowX", fHslider9, 1.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[1] EQ/midX", fHslider5, 1.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[1] EQ/highX", fHslider10, 1.0f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[1] EQ/lowBand", fHslider4, 5e+02f, 1e+02f, 6e+03f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[1] EQ/highBand", fHslider6, 2e+03f, 1e+03f, 1e+04f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[2] Mod/mDepth", fHslider7, 0.1f, 0.0f, 1.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("[0] JPrev/[2] Mod/mFreq", fHslider8, 2.0f, 0.0f, 1e+01f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, earlyDiff, "[0] JPrev/[0] Mix/earlyDiff", fHslider0, 0.70710677f, 0.0f, 0.99f, 0.001f) \
		p(HORIZONTALSLIDER, size, "[0] JPrev/[0] Mix/size", fHslider2, 1.0f, 0.5f, 3.0f, 0.01f) \
		p(HORIZONTALSLIDER, t60, "[0] JPrev/[0] Mix/t60", fHslider3, 1.0f, 0.1f, 6e+01f, 0.1f) \
		p(HORIZONTALSLIDER, damp, "[0] JPrev/[0] Mix/damp", fHslider1, 0.0f, 0.0f, 0.999f, 0.0001f) \
		p(HORIZONTALSLIDER, lowX, "[0] JPrev/[1] EQ/lowX", fHslider9, 1.0f, 0.0f, 1.0f, 0.01f) \
		p(HORIZONTALSLIDER, midX, "[0] JPrev/[1] EQ/midX", fHslider5, 1.0f, 0.0f, 1.0f, 0.01f) \
		p(HORIZONTALSLIDER, highX, "[0] JPrev/[1] EQ/highX", fHslider10, 1.0f, 0.0f, 1.0f, 0.01f) \
		p(HORIZONTALSLIDER, lowBand, "[0] JPrev/[1] EQ/lowBand", fHslider4, 5e+02f, 1e+02f, 6e+03f, 0.1f) \
		p(HORIZONTALSLIDER, highBand, "[0] JPrev/[1] EQ/highBand", fHslider6, 2e+03f, 1e+03f, 1e+04f, 0.1f) \
		p(HORIZONTALSLIDER, mDepth, "[0] JPrev/[2] Mod/mDepth", fHslider7, 0.1f, 0.0f, 1.0f, 0.001f) \
		p(HORIZONTALSLIDER, mFreq, "[0] JPrev/[2] Mod/mFreq", fHslider8, 2.0f, 0.0f, 1e+01f, 0.01f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
