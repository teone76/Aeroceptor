/* Include files */

#include "simulatoreWONDERS_sfun.h"
#include "simulatoreWONDERS_sfun_debug_macros.h"
#include "c1_simulatoreWONDERS.h"
#include "c2_simulatoreWONDERS.h"
#include "c3_simulatoreWONDERS.h"
#include "c4_simulatoreWONDERS.h"
#include "c5_simulatoreWONDERS.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _simulatoreWONDERSMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void simulatoreWONDERS_initializer(void)
{
}

void simulatoreWONDERS_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_simulatoreWONDERS_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_simulatoreWONDERS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_simulatoreWONDERS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_simulatoreWONDERS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_simulatoreWONDERS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_simulatoreWONDERS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_simulatoreWONDERS_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2825097056U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3350838610U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2671064346U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(289657655U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2805641891U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1489595852U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(172546080U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2708722222U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_simulatoreWONDERS_get_check_sum(mxArray *plhs[]);
          sf_c1_simulatoreWONDERS_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_simulatoreWONDERS_get_check_sum(mxArray *plhs[]);
          sf_c2_simulatoreWONDERS_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_simulatoreWONDERS_get_check_sum(mxArray *plhs[]);
          sf_c3_simulatoreWONDERS_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_simulatoreWONDERS_get_check_sum(mxArray *plhs[]);
          sf_c4_simulatoreWONDERS_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_simulatoreWONDERS_get_check_sum(mxArray *plhs[]);
          sf_c5_simulatoreWONDERS_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3269119057U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(869186348U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1181654030U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4060389767U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_simulatoreWONDERS_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "inHNgM8ol2ss1eKAgRr8HG") == 0) {
          extern mxArray *sf_c1_simulatoreWONDERS_get_autoinheritance_info(void);
          plhs[0] = sf_c1_simulatoreWONDERS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "PCqhV7Ka7K4UqFOu9IfVVC") == 0) {
          extern mxArray *sf_c2_simulatoreWONDERS_get_autoinheritance_info(void);
          plhs[0] = sf_c2_simulatoreWONDERS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "pkeSNpkyH6GDE2XbO2tVpF") == 0) {
          extern mxArray *sf_c3_simulatoreWONDERS_get_autoinheritance_info(void);
          plhs[0] = sf_c3_simulatoreWONDERS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "wfZpIZWLHnlqTarsBFOgvF") == 0) {
          extern mxArray *sf_c4_simulatoreWONDERS_get_autoinheritance_info(void);
          plhs[0] = sf_c4_simulatoreWONDERS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "qkEWEGoKAveqYQAf5XEEVB") == 0) {
          extern mxArray *sf_c5_simulatoreWONDERS_get_autoinheritance_info(void);
          plhs[0] = sf_c5_simulatoreWONDERS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_simulatoreWONDERS_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_simulatoreWONDERS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_simulatoreWONDERS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_simulatoreWONDERS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_simulatoreWONDERS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_simulatoreWONDERS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_simulatoreWONDERS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_simulatoreWONDERS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_simulatoreWONDERS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_simulatoreWONDERS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_simulatoreWONDERS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_simulatoreWONDERS_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "XRhRD50ktFJKamFhRGLyVB") == 0) {
          extern mxArray *sf_c1_simulatoreWONDERS_third_party_uses_info(void);
          plhs[0] = sf_c1_simulatoreWONDERS_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NRShtXxOTBEOxOZCOvQN9B") == 0) {
          extern mxArray *sf_c2_simulatoreWONDERS_third_party_uses_info(void);
          plhs[0] = sf_c2_simulatoreWONDERS_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "PFfxtbYl4FRAy8eBzun3iG") == 0) {
          extern mxArray *sf_c3_simulatoreWONDERS_third_party_uses_info(void);
          plhs[0] = sf_c3_simulatoreWONDERS_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "1GeHVlWLpCQMJyHRPpp4IE") == 0) {
          extern mxArray *sf_c4_simulatoreWONDERS_third_party_uses_info(void);
          plhs[0] = sf_c4_simulatoreWONDERS_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "7mxSYvjIZhmRXZ0DSl4Tq") == 0) {
          extern mxArray *sf_c5_simulatoreWONDERS_third_party_uses_info(void);
          plhs[0] = sf_c5_simulatoreWONDERS_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_simulatoreWONDERS_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "XRhRD50ktFJKamFhRGLyVB") == 0) {
          extern mxArray *sf_c1_simulatoreWONDERS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_simulatoreWONDERS_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NRShtXxOTBEOxOZCOvQN9B") == 0) {
          extern mxArray *sf_c2_simulatoreWONDERS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_simulatoreWONDERS_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "PFfxtbYl4FRAy8eBzun3iG") == 0) {
          extern mxArray *sf_c3_simulatoreWONDERS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_simulatoreWONDERS_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "1GeHVlWLpCQMJyHRPpp4IE") == 0) {
          extern mxArray *sf_c4_simulatoreWONDERS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_simulatoreWONDERS_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "7mxSYvjIZhmRXZ0DSl4Tq") == 0) {
          extern mxArray *sf_c5_simulatoreWONDERS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_simulatoreWONDERS_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void simulatoreWONDERS_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _simulatoreWONDERSMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "simulatoreWONDERS","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _simulatoreWONDERSMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _simulatoreWONDERSMachineNumber_,0);
}

void simulatoreWONDERS_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_simulatoreWONDERS_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "simulatoreWONDERS", "simulatoreWONDERS");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_simulatoreWONDERS_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
