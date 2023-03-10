/*
 * soh_sf_data.c
 *
 * Code generation for model "soh_sf".
 *
 * Model version              : 1.270
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed May 27 10:32:13 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "soh_sf.h"
#include "soh_sf_private.h"

/* Block parameters (auto storage) */
P_soh_T soh_DefaultP = {
  /*  Variable: bmsc_InternalDischgResistX
   * Referenced by: '<S5>/2-D Lookup Table1'
   */
  { 0.0, 23.0, 40.0 },

  /*  Variable: bmsc_InternalDischgResistY
   * Referenced by: '<S5>/2-D Lookup Table1'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0,
    14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0,
    27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,
    40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0,
    53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0,
    66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0,
    79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0,
    92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0 },

  /*  Variable: bmsc_InternalDischgResistZ
   * Referenced by: '<S5>/2-D Lookup Table1'
   */
  { 0.05249628, 0.014089, 0.006173875, 0.05091366, 0.01372175, 0.006032026,
    0.04938268, 0.01336513, 0.005893943, 0.04790223, 0.013019, 0.0057596,
    0.04647125, 0.01268322, 0.005628965, 0.04508867, 0.01235763, 0.005502011,
    0.04375343, 0.01204211, 0.005378707, 0.04246451, 0.01173649, 0.005259021,
    0.04122086, 0.01144065, 0.005142922, 0.04002149, 0.01115442, 0.005030376,
    0.03886538, 0.01087768, 0.004921351, 0.03775155, 0.01061027, 0.004815812,
    0.03667903, 0.01035204, 0.004713724, 0.03564685, 0.01010285, 0.004615052,
    0.03465406, 0.009862557, 0.004519758, 0.03369972, 0.009631008, 0.004427806,
    0.0327829, 0.009408057, 0.004339157, 0.03190268, 0.009193555, 0.004253772,
    0.03105815, 0.008987356, 0.004171613, 0.03024843, 0.00878931, 0.004092638,
    0.02947262, 0.008599269, 0.004016806, 0.02872985, 0.008417083, 0.003944076,
    0.02801926, 0.008242603, 0.003874404, 0.02733999, 0.008075679, 0.003807748,
    0.02669121, 0.007916161, 0.003744062, 0.02607208, 0.007763898, 0.003683302,
    0.02548178, 0.007618741, 0.003625422, 0.02491949, 0.007480537, 0.003570375,
    0.02438441, 0.007349135, 0.003518115, 0.02387576, 0.007224383, 0.003468592,
    0.02339273, 0.00710613, 0.003421757, 0.02293457, 0.006994223, 0.003377562,
    0.02250051, 0.00688851, 0.003335956, 0.02208978, 0.006788836, 0.003296886,
    0.02170165, 0.00669505, 0.003260302, 0.02133537, 0.006606998, 0.003226151,
    0.02099021, 0.006524525, 0.003194378, 0.02066545, 0.006447477, 0.003164929,
    0.02036038, 0.006375701, 0.00313775, 0.0200743, 0.00630904, 0.003112784,
    0.0198065, 0.006247341, 0.003089975, 0.0195563, 0.006190447, 0.003069265,
    0.01932302, 0.006138204, 0.003050595, 0.01910598, 0.006090455, 0.003033908,
    0.01890453, 0.006047043, 0.003019143, 0.018718, 0.006007813, 0.003006239,
    0.01854574, 0.005972608, 0.002995135, 0.01838711, 0.00594127, 0.00298577,
    0.01824147, 0.005913642, 0.00297808, 0.01810821, 0.005889567, 0.002972001,
    0.01798668, 0.005868886, 0.00296747, 0.01787629, 0.005851442, 0.002964421,
    0.01777643, 0.005837076, 0.002962788, 0.01768648, 0.005825629, 0.002962504,
    0.01760587, 0.005816943, 0.002963503, 0.017534, 0.005810857, 0.002965716,
    0.01747029, 0.005807213, 0.002969074, 0.01741416, 0.005805851, 0.002973508,
    0.01736506, 0.005806611, 0.002978946, 0.01732241, 0.005809332, 0.002985319,
    0.01728566, 0.005813854, 0.002992553, 0.01725425, 0.005820016, 0.003000577,
    0.01722766, 0.005827657, 0.003009317, 0.01720533, 0.005836616, 0.003018699,
    0.01718673, 0.005846731, 0.003028648, 0.01717133, 0.005857841, 0.003039089,
    0.01715862, 0.005869784, 0.003049945, 0.01714808, 0.005882396, 0.003061139,
    0.0171392, 0.005895517, 0.003072594, 0.01713146, 0.005908982, 0.00308423,
    0.01712437, 0.00592263, 0.00309597, 0.01711744, 0.005936296, 0.003107733,
    0.01711017, 0.005949818, 0.003119438, 0.01710208, 0.005963032, 0.003131005,
    0.01709268, 0.005975774, 0.003142351, 0.01708151, 0.005987879, 0.003153393,
    0.01706808, 0.005999184, 0.003164048, 0.01705193, 0.006009524, 0.003174233,
    0.01703261, 0.006018735, 0.003183862, 0.01700964, 0.006026651, 0.003192849,
    0.01698259, 0.006033106, 0.00320111, 0.01695099, 0.006037937, 0.003208556,
    0.01691441, 0.006040977, 0.003215101, 0.0168724, 0.00604206, 0.003220656,
    0.01682452, 0.006041021, 0.003225133, 0.01677035, 0.006037692, 0.003228442,
    0.01670945, 0.006031909, 0.003230493, 0.0166414, 0.006023503, 0.003231195,
    0.01656578, 0.006012309, 0.003230457, 0.01648217, 0.00599816, 0.003228187,
    0.01639015, 0.005980888, 0.003224291, 0.01628932, 0.005960325, 0.003218678,
    0.01617927, 0.005936305, 0.003211252, 0.0160596, 0.00590866, 0.00320192,
    0.0159299, 0.005877221, 0.003190585, 0.01578978, 0.005841821, 0.003177153,
    0.01563884, 0.005802291, 0.003161526, 0.0154767, 0.005758463, 0.003143609,
    0.01530297, 0.005710169, 0.003123302, 0.01511727, 0.005657239, 0.003100509,
    0.01491921, 0.005599505, 0.003075129 },
  0.1,                                 /* Variable: sohc_current_threshold
                                        * Referenced by: '<S9>/Constant2'
                                        */
  0.9,                                 /* Variable: sohc_customer_filter_coeff
                                        * Referenced by:
                                        *   '<S7>/Gain1'
                                        *   '<S7>/Gain2'
                                        *   '<S7>/Gain6'
                                        *   '<S7>/Gain7'
                                        */
  0.9995,                              /* Variable: sohc_filter_coeff
                                        * Referenced by:
                                        *   '<S8>/Gain6'
                                        *   '<S8>/Gain7'
                                        */
  30.0,                                /* Variable: sohc_pct_R_limit
                                        * Referenced by: '<S8>/Gain8'
                                        */
  1.1,                                 /* Variable: sohk_CellBalancingResistor
                                        * Referenced by: '<S5>/Constant4'
                                        */

  /*  Variable: sohv_factoryInit_sohc
   * Referenced by: '<S7>/Delay1'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  Variable: sohv_factoryInit_sohr
   * Referenced by:
   *   '<S1>/Data Store Memory1'
   *   '<S7>/Delay3'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }
};

/* Constant parameters (auto storage) */
const ConstP_soh_T soh_ConstP = {
  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S5>/2-D Lookup Table1'
   */
  { 2U, 100U }
};
