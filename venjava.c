/* venjava.c Copyright 1999 ventana Systems, Inc. 
   This program provides glue between Java and the Vensim DLL
   */

#include <jni.h>
/* note that you may need to set include paths to find jni.h */
#ifdef unix
typedef long V4BYTES ;
typedef V4BYTES HANDLE ;
typedef V4BYTES HWND ;
#define IDOK 1
typedef int (*FARPROC)();
typedef int (*DLGPROC)();
typedef void * HINSTANCE ;
#define EXPORTED_PROC
#else
#include <windows.h>
#endif
#include "..\vendll.h"
//#include "..\vensim.h"

JNIEXPORT jint JNICALL Java_Vensim_ContextAdd(JNIEnv *jenv, jobject jobj, jint wantclean)
{
   jint rval ;
   rval = VensimContextAdd(wantclean) ;
   return rval ;
   }
JNIEXPORT jint JNICALL Java_Vensim_ContextDrop(JNIEnv *jenv, jobject jobj, jint context)
{
   jint rval ;
   rval = VensimContextDrop(context) ;
   return rval ;
   }

JNIEXPORT jint JNICALL Java_Vensim_command(JNIEnv *jenv,jobject jobj,jstring jcommand) 
 {
  const char *command ;
  jint jrval ;
         
  command = (*jenv)->GetStringUTFChars(jenv, jcommand, 0) ;
  jrval = (jint)vensim_command(command) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jcommand, command) ;
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CCommand(JNIEnv *jenv,jobject jobj,jint context,jstring jcommand)
 {
  const char *command ;
  jint jrval ;
         
  command = (*jenv)->GetStringUTFChars(jenv, jcommand, 0) ;
  jrval = (jint)VensimCCommand(context,command) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jcommand, command) ;
  return(jrval) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_get_1data(JNIEnv *jenv,jobject jobj,
      jstring jfilename,jstring jvarname,jstring jtname,
      jfloatArray jvval,jfloatArray jtval,jint jmaxn) 
 {
  float *vval,*tval ;
  char *filename,*varname,*tname ;
  jint jrval ;

  filename = (char *)((*jenv)->GetStringUTFChars(jenv, jfilename, 0)) ;
  varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0)) ;
  tname = (char *)((*jenv)->GetStringUTFChars(jenv, jtname, 0))    ;
  vval = (*jenv)->GetFloatArrayElements(jenv, jvval, 0) ;
  tval = (*jenv)->GetFloatArrayElements(jenv, jtval, 0) ;
  jrval = (jint)vensim_get_data(filename,varname,tname,vval,tval,(int)jmaxn) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jfilename, filename) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jtname, tname) ;
  (*jenv)->ReleaseFloatArrayElements(jenv, jvval, vval, 0);
  (*jenv)->ReleaseFloatArrayElements(jenv, jtval, tval, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_VensimCGetData(JNIEnv *jenv,jobject jobj,jint context,
      jstring jfilename,jstring jvarname,jstring jtname,
      jfloatArray jvval,jfloatArray jtval,jint jmaxn) 
 {
  float *vval,*tval ;
  char *filename,*varname,*tname ;
  jint jrval ;

  filename = (char *)((*jenv)->GetStringUTFChars(jenv, jfilename, 0)) ;
  varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0)) ;
  tname = (char *)((*jenv)->GetStringUTFChars(jenv, jtname, 0))    ;
  vval = (*jenv)->GetFloatArrayElements(jenv, jvval, 0) ;
  tval = (*jenv)->GetFloatArrayElements(jenv, jtval, 0) ;
  jrval = (jint)VensimCGetData(context,filename,varname,tname,vval,tval,(int)jmaxn) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jfilename, filename) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jtname, tname) ;
  (*jenv)->ReleaseFloatArrayElements(jenv, jvval, vval, 0);
  (*jenv)->ReleaseFloatArrayElements(jenv, jtval, tval, 0);
  return(jrval) ;
  }


JNIEXPORT jint JNICALL Java_Vensim_tool_1command(JNIEnv *jenv,jobject jobj,jstring jcommand,
        jint jwindow,jint jaswiptool) 
 {
  const char *command ;
  jint jrval ;
         
  command = (*jenv)->GetStringUTFChars(jenv, jcommand, 0) ;
  jrval = (jint)vensim_tool_command(command,(HWND)jwindow,(int)jaswiptool) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jcommand, command) ;
  return(jrval) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_CToolCommand(JNIEnv *jenv,jobject jobj,jint context,jstring jcommand,
        jint jwindow,jint jaswiptool) 
 {
  const char *command ;
  jint jrval ;
         
  command = (*jenv)->GetStringUTFChars(jenv, jcommand, 0) ;
  jrval = (jint)VensimCToolCommand(context,command,(HWND)jwindow,(int)jaswiptool) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jcommand, command) ;
  return(jrval) ;
  }


JNIEXPORT jint JNICALL Java_Vensim_start_1simulation(JNIEnv *jenv,jobject jobj,
     jint jloadfirst,jint jgame,jint joverwrite)
 {
  jint rval ;
  rval = (jint)vensim_start_simulation((int)jloadfirst,(int)jgame,(int)joverwrite) ;
  return(rval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CStartSimulation(JNIEnv *jenv,jobject jobj,jint context,
     jint jloadfirst,jint jgame,jint joverwrite)
 {
  jint rval ;
  rval = (jint)VensimCStartSimulation(context,(int)jloadfirst,(int)jgame,(int)joverwrite) ;
  return(rval) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_continue_1simulation(JNIEnv *jenv,jobject jobj,
     jint jnum_iter)
 {
  jint rval ;
  rval = (jint)vensim_continue_simulation((int)jnum_iter) ;
  return(rval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CContinueSimulation(JNIEnv *jenv,jobject jobj,jint context,
     jint jnum_iter)
 {
  jint rval ;
  rval = (jint)VensimCContinueSimulation(context,(int)jnum_iter) ;
  return(rval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_finish_1simulation(JNIEnv *jenv,jobject jobj)
 {
  return((jint)vensim_finish_simulation()) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CFinishSimulation(JNIEnv *jenv,jobject jobj,jint context)
 {
  return((jint)VensimCFinishSimulation(context)) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_get_1val(JNIEnv *jenv,jobject jobj,
      jstring jname,jfloatArray jval) 
 {
  float *val ;
  char *name ;
  jint jrval ;

  name = (char *)((*jenv)->GetStringUTFChars(jenv, jname, 0))    ;
  val = (*jenv)->GetFloatArrayElements(jenv, jval, 0) ;
  jrval = (jint)vensim_get_val(name,val) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jname, name) ;
  (*jenv)->ReleaseFloatArrayElements(jenv, jval, val, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CGetVal(JNIEnv *jenv,jobject jobj,jint context,
      jstring jname,jfloatArray jval) 
 {
  float *val ;
  char *name ;
  jint jrval ;

  name = (char *)((*jenv)->GetStringUTFChars(jenv, jname, 0))    ;
  val = (*jenv)->GetFloatArrayElements(jenv, jval, 0) ;
  jrval = (jint)VensimCGetVal(context,name,val) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jname, name) ;
  (*jenv)->ReleaseFloatArrayElements(jenv, jval, val, 0);
  return(jrval) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_get_1dpval(JNIEnv *jenv,jobject jobj,
      jstring jname,jdoubleArray jval) 
 {
  double *val ;
  char *name ;
  jint jrval ;

  name = (char *)((*jenv)->GetStringUTFChars(jenv, jname, 0))    ;
  val = (*jenv)->GetDoubleArrayElements(jenv, jval, 0) ;
  jrval = (jint)vensim_get_dpval(name,val) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jname, name) ;
  (*jenv)->ReleaseDoubleArrayElements(jenv, jval, val, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CGetDPVal(JNIEnv *jenv,jobject jobj,jint context,
      jstring jname,jdoubleArray jval) 
 {
  double *val ;
  char *name ;
  jint jrval ;

  name = (char *)((*jenv)->GetStringUTFChars(jenv, jname, 0))    ;
  val = (*jenv)->GetDoubleArrayElements(jenv, jval, 0) ;
  jrval = (jint)VensimCGetDPVal(context,name,val) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jname, name) ;
  (*jenv)->ReleaseDoubleArrayElements(jenv, jval, val, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_show_1sketch(JNIEnv *jenv,jobject jobj,
     jint jsketchnum,jint jwantscroll,jint jzoompercent,jint jpwindow)
  {
   return((jint)vensim_show_sketch((int)jsketchnum,(int)jwantscroll,
         (int)jzoompercent,(HWND)jpwindow)) ;
   } 
JNIEXPORT jint JNICALL Java_Vensim_CShowSketch(JNIEnv *jenv,jobject jobj,jint context,
     jint jsketchnum,jint jwantscroll,jint jzoompercent,jint jpwindow)
  {
   return((jint)VensimCShowSketch(context,(int)jsketchnum,(int)jwantscroll,
         (int)jzoompercent,(HWND)jpwindow)) ;
   } 
JNIEXPORT jint JNICALL Java_Vensim_be_1quiet(JNIEnv *jenv,jobject jobj,
        jint jquietflag)
  {
   return((jint)vensim_be_quiet((int)jquietflag)) ;
   }
JNIEXPORT jint JNICALL Java_Vensim_CBeQuiet(JNIEnv *jenv,jobject jobj,jint context,
        jint jquietflag)
  {
   return((jint)VensimCBeQuiet(context,(int)jquietflag)) ;
   }
JNIEXPORT jint JNICALL Java_Vensim_check_1status(JNIEnv *jenv,jobject jobj)
 {
  return((jint)vensim_check_status()) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CCheckStatus(JNIEnv *jenv,jobject jobj,jint context)
 {
  return((jint)VensimCCheckStatus(context)) ;
  }

JNIEXPORT jobjectArray JNICALL Java_Vensim_get_1varnames(JNIEnv *jenv,jobject jobj,
            jstring jfilter,jint jvartype)
{
   char *filter,*buf ;
   int bufsize ;
   jobjectArray jlist ;
   int count ;
   char *tv ;

   filter = (char *)((*jenv)->GetStringUTFChars(jenv, jfilter, 0)) ;

   bufsize = vensim_get_varnames(filter,(int)jvartype,'\0',0) ;
   if(bufsize > 1) {
      bufsize++ ; /* bug in vensim_get_varnames need one more space */
      buf = malloc(bufsize) ;
      vensim_get_varnames(filter,(int)jvartype,buf,bufsize) ;
      for(count=0,tv=buf;*tv;tv++,count++) {
         while(*tv)
            tv++ ;
         }
      }
   else
      count = 0 ;
   jlist = (*jenv)->NewObjectArray(jenv,count,(*jenv)->FindClass(jenv,"java/lang/String"),
      (*jenv)->NewStringUTF(jenv,"")) ;   
   if(bufsize > 1) {
      for(count=0,tv=buf;*tv;tv++,count++) {
         (*jenv)->SetObjectArrayElement(jenv,jlist,count,(*jenv)->NewStringUTF(jenv,tv)) ;
         while(*tv)
            tv++ ;
         }
      free(buf) ;
      }
   (*jenv)->ReleaseStringUTFChars(jenv, jfilter, filter) ;
   return jlist ;
   }
JNIEXPORT jobjectArray JNICALL Java_Vensim_CGetVarNames(JNIEnv *jenv,jobject jobj,jint context,
            jstring jfilter,jint jvartype)
{
   char *filter,*buf ;
   int bufsize ;
   jobjectArray jlist ;
   int count ;
   char *tv ;

   filter = (char *)((*jenv)->GetStringUTFChars(jenv, jfilter, 0)) ;

   bufsize = VensimCGetVarNames(context,filter,(int)jvartype,'\0',0) ;
   if(bufsize > 1) {
      bufsize++ ; /* bug in vensim_get_varnames need one more space */
      buf = malloc(bufsize) ;
      vensim_get_varnames(filter,(int)jvartype,buf,bufsize) ;
      for(count=0,tv=buf;*tv;tv++,count++) {
         while(*tv)
            tv++ ;
         }
      }
   else
      count = 0 ;
   jlist = (*jenv)->NewObjectArray(jenv,count,(*jenv)->FindClass(jenv,"java/lang/String"),
      (*jenv)->NewStringUTF(jenv,"")) ;   
   if(bufsize > 1) {
      for(count=0,tv=buf;*tv;tv++,count++) {
         (*jenv)->SetObjectArrayElement(jenv,jlist,count,(*jenv)->NewStringUTF(jenv,tv)) ;
         while(*tv)
            tv++ ;
         }
      free(buf) ;
      }
   (*jenv)->ReleaseStringUTFChars(jenv, jfilter, filter) ;
   return jlist ;
   }


JNIEXPORT jobjectArray JNICALL Java_Vensim_get_1varattrib(JNIEnv *jenv,jobject jobj,
            jstring jvarname,jint jattrib)
{
   char *varname,*buf ;
   int bufsize ;
   jobjectArray jlist ;
   int count ;
   char *tv ;

   varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0)) ;

   bufsize = vensim_get_varattrib(varname,(int)jattrib,'\0',0) ;
   if(bufsize > 1) {
      buf = malloc(bufsize) ;
      vensim_get_varattrib(varname,(int)jattrib,buf,bufsize) ;
      for(count=0,tv=buf;*tv;tv++,count++) {
         while(*tv)
            tv++ ;
         }
      }
   else
      count = 0 ;
   jlist = (*jenv)->NewObjectArray(jenv,count,(*jenv)->FindClass(jenv,"java/lang/String"),
      (*jenv)->NewStringUTF(jenv,"")) ;   
   if(bufsize > 1) {
      for(count=0,tv=buf;*tv;tv++,count++) {
         (*jenv)->SetObjectArrayElement(jenv,jlist,count,(*jenv)->NewStringUTF(jenv,tv)) ;
         while(*tv)
            tv++ ;
         }
      free(buf) ;
      }
   (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
   return jlist ;
   }
JNIEXPORT jobjectArray JNICALL Java_Vensim_CGetVarAttrib(JNIEnv *jenv,jobject jobj,jint context,
            jstring jvarname,jint jattrib)
{
   char *varname,*buf ;
   int bufsize ;
   jobjectArray jlist ;
   int count ;
   char *tv ;

   varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0)) ;

   bufsize = vensim_get_varattrib(varname,(int)jattrib,'\0',0) ;
   if(bufsize > 1) {
      buf = malloc(bufsize) ;
      VensimCGetVarAttrib(context,varname,(int)jattrib,buf,bufsize) ;
      for(count=0,tv=buf;*tv;tv++,count++) {
         while(*tv)
            tv++ ;
         }
      }
   else
      count = 0 ;
   jlist = (*jenv)->NewObjectArray(jenv,count,(*jenv)->FindClass(jenv,"java/lang/String"),
      (*jenv)->NewStringUTF(jenv,"")) ;   
   if(bufsize > 1) {
      for(count=0,tv=buf;*tv;tv++,count++) {
         (*jenv)->SetObjectArrayElement(jenv,jlist,count,(*jenv)->NewStringUTF(jenv,tv)) ;
         while(*tv)
            tv++ ;
         }
      free(buf) ;
      }
   (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
   return jlist ;
   }


JNIEXPORT jint JNICALL Java_Vensim_get_1substring(JNIEnv *jenv,jobject jobj,
            jstring jfullstring,jint joffset,jstring jbuf,jint jmaxbuflen)
{
   jint jrval ;
   char *fullstring,*buf ;
   fullstring = (char *)((*jenv)->GetStringUTFChars(jenv, jfullstring, 0))    ;
   buf = (char *)((*jenv)->GetStringUTFChars(jenv, jbuf, 0))    ;
   jrval = (jint)vensim_get_substring(fullstring,(int)joffset,buf,(int)jmaxbuflen) ;
   (*jenv)->ReleaseStringUTFChars(jenv, jfullstring, fullstring) ;
   (*jenv)->ReleaseStringUTFChars(jenv, jbuf, buf) ;
   return(jrval) ;
   }

JNIEXPORT jobjectArray JNICALL Java_Vensim_get_1info(JNIEnv *jenv,jobject jobj,
            jint jinfowanted)
{
   char *buf ;
   int bufsize ;
   jobjectArray jlist ;
   int count ;
   char *tv ;


   bufsize = vensim_get_info((int)jinfowanted,'\0',0) ;
   bufsize++ ; /* there is a bug in vensim_get_info */
   if(bufsize > 2) {
      buf = malloc(bufsize) ;
      vensim_get_info((int)jinfowanted,buf,bufsize) ;
      for(count=0,tv=buf;*tv;tv++,count++) {
         while(*tv)
            tv++ ;
         }
      }
   else
      count = 0 ;
   jlist = (*jenv)->NewObjectArray(jenv,count,(*jenv)->FindClass(jenv,"java/lang/String"),
      (*jenv)->NewStringUTF(jenv,"")) ;   
   if(bufsize > 1) {
      for(count=0,tv=buf;*tv;tv++,count++) {
         (*jenv)->SetObjectArrayElement(jenv,jlist,count,(*jenv)->NewStringUTF(jenv,tv)) ;
         while(*tv)
            tv++ ;
         }
      free(buf) ;
      }
   return jlist ;
   }
JNIEXPORT jobjectArray JNICALL Java_Vensim_CGetInfo(JNIEnv *jenv,jobject jobj,jint context,
            jint jinfowanted)
{
   char *buf ;
   int bufsize ;
   jobjectArray jlist ;
   int count ;
   char *tv ;


   bufsize = VensimCGetInfo(context,(int)jinfowanted,'\0',0) ;
   bufsize++ ; /* there is a bug in vensim_get_info */
   if(bufsize > 2) {
      buf = malloc(bufsize) ;
      vensim_get_info((int)jinfowanted,buf,bufsize) ;
      for(count=0,tv=buf;*tv;tv++,count++) {
         while(*tv)
            tv++ ;
         }
      }
   else
      count = 0 ;
   jlist = (*jenv)->NewObjectArray(jenv,count,(*jenv)->FindClass(jenv,"java/lang/String"),
      (*jenv)->NewStringUTF(jenv,"")) ;   
   if(bufsize > 1) {
      for(count=0,tv=buf;*tv;tv++,count++) {
         (*jenv)->SetObjectArrayElement(jenv,jlist,count,(*jenv)->NewStringUTF(jenv,tv)) ;
         while(*tv)
            tv++ ;
         }
      free(buf) ;
      }
   return jlist ;
   }


JNIEXPORT jint JNICALL Java_Vensim_get_1jversion(JNIEnv *jenv,jobject jobj)
{
   return 5000 ;
   }

JNIEXPORT jint JNICALL Java_Vensim_get_1varoff(JNIEnv *jenv,jobject jobj,
            jstring jvarname)
{
   jint jrval ;
   char *varname ;
   varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0))    ;
   jrval = (jint)vensim_get_varoff(varname) ;
   (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
   return(jrval) ;
   }
JNIEXPORT jint JNICALL Java_Vensim_CGetVarOff(JNIEnv *jenv,jobject jobj,jint context,
            jstring jvarname)
{
   jint jrval ;
   char *varname ;
   varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0))    ;
   jrval = (jint)VensimCGetVarOff(context,varname) ;
   (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
   return(jrval) ;
   }

JNIEXPORT jint JNICALL Java_Vensim_get_1vecvals(JNIEnv *jenv,jobject jobj,
      jintArray jvecoff,jfloatArray jvals,jint jnvals) 
 {
  float *vals ;
  unsigned long *vecoff ;
  jint jrval ;

  vecoff = (*jenv)->GetIntArrayElements(jenv, jvecoff, 0) ;
  vals = (*jenv)->GetFloatArrayElements(jenv, jvals, 0) ;
  jrval = (jint)vensim_get_vecvals(vecoff,vals,(int)jnvals) ;
  (*jenv)->ReleaseIntArrayElements(jenv, jvecoff, vecoff, 0);
  (*jenv)->ReleaseFloatArrayElements(jenv, jvals, vals, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CGetVecVals(JNIEnv *jenv,jobject jobj,jint context,
      jintArray jvecoff,jfloatArray jvals,jint jnvals) 
 {
  float *vals ;
  unsigned long *vecoff ;
  jint jrval ;

  vecoff = (*jenv)->GetIntArrayElements(jenv, jvecoff, 0) ;
  vals = (*jenv)->GetFloatArrayElements(jenv, jvals, 0) ;
  jrval = (jint)VensimCGetVecVals(context,vecoff,vals,(int)jnvals) ;
  (*jenv)->ReleaseIntArrayElements(jenv, jvecoff, vecoff, 0);
  (*jenv)->ReleaseFloatArrayElements(jenv, jvals, vals, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_get_1dpvecvals(JNIEnv *jenv,jobject jobj,
      jintArray jvecoff,jdoubleArray jvals,jint jnvals) 
 {
  double *vals ;
  unsigned long *vecoff ;
  jint jrval ;

  vecoff = (*jenv)->GetIntArrayElements(jenv, jvecoff, 0) ;
  vals = (*jenv)->GetDoubleArrayElements(jenv, jvals, 0) ;
  jrval = (jint)vensim_get_dpvecvals(vecoff,vals,(int)jnvals) ;
  (*jenv)->ReleaseIntArrayElements(jenv, jvecoff, vecoff, 0);
  (*jenv)->ReleaseDoubleArrayElements(jenv, jvals, vals, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CGetDPVecVals(JNIEnv *jenv,jobject jobj,jint context,
      jintArray jvecoff,jdoubleArray jvals,jint jnvals) 
 {
  double *vals ;
  unsigned long *vecoff ;
  jint jrval ;

  vecoff = (*jenv)->GetIntArrayElements(jenv, jvecoff, 0) ;
  vals = (*jenv)->GetDoubleArrayElements(jenv, jvals, 0) ;
  jrval = (jint)VensimCGetDPVecVals(context,vecoff,vals,(int)jnvals) ;
  (*jenv)->ReleaseIntArrayElements(jenv, jvecoff, vecoff, 0);
  (*jenv)->ReleaseDoubleArrayElements(jenv, jvals, vals, 0);
  return(jrval) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_get_1sens_at_time(JNIEnv *jenv,jobject jobj,
      jstring jfilename,jstring jvarname,jstring jtname,
      jfloatArray jintime,jfloatArray jvals,jint jmaxn) 
 {
  float *intime,*vals ;
  char *filename,*varname,*tname ;
  jint jrval ;

  filename = (char *)((*jenv)->GetStringUTFChars(jenv, jfilename, 0)) ;
  varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0)) ;
  tname = (char *)((*jenv)->GetStringUTFChars(jenv, jtname, 0))    ;
  vals = (*jenv)->GetFloatArrayElements(jenv, jvals, 0) ;
  intime = (*jenv)->GetFloatArrayElements(jenv, jintime, 0) ;
  jrval = (jint)vensim_get_sens_at_time(filename,varname,tname,intime,vals,(int)jmaxn) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jfilename, filename) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jtname, tname) ;
  (*jenv)->ReleaseFloatArrayElements(jenv, jvals, vals, 0);
  (*jenv)->ReleaseFloatArrayElements(jenv, jintime, intime, 0);
  return(jrval) ;
  }
JNIEXPORT jint JNICALL Java_Vensim_CGetSensAtTime(JNIEnv *jenv,jobject jobj,jint context,
      jstring jfilename,jstring jvarname,jstring jtname,
      jfloatArray jintime,jfloatArray jvals,jint jmaxn) 
 {
  float *intime,*vals ;
  char *filename,*varname,*tname ;
  jint jrval ;

  filename = (char *)((*jenv)->GetStringUTFChars(jenv, jfilename, 0)) ;
  varname = (char *)((*jenv)->GetStringUTFChars(jenv, jvarname, 0)) ;
  tname = (char *)((*jenv)->GetStringUTFChars(jenv, jtname, 0))    ;
  vals = (*jenv)->GetFloatArrayElements(jenv, jvals, 0) ;
  intime = (*jenv)->GetFloatArrayElements(jenv, jintime, 0) ;
  jrval = (jint)VensimCGetSensAtTime(context,filename,varname,tname,intime,vals,(int)jmaxn) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jfilename, filename) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jvarname, varname) ;
  (*jenv)->ReleaseStringUTFChars(jenv, jtname, tname) ;
  (*jenv)->ReleaseFloatArrayElements(jenv, jvals, vals, 0);
  (*jenv)->ReleaseFloatArrayElements(jenv, jintime, intime, 0);
  return(jrval) ;
  }

JNIEXPORT jint JNICALL Java_Vensim_set_1parent_window(JNIEnv *jenv,jobject jobj,
        jint jwin,jint jr1,jint jr2)
  {
   return((jint)vensim_set_parent_window((HWND)jwin,(long)jr1,(long)jr2)) ;
   }
JNIEXPORT jint JNICALL Java_Vensim_CSetParentWindow(JNIEnv *jenv,jobject jobj,int context,
        jint jwin,jint jr1,jint jr2)
  {
   return((jint)VensimCSetParentWindow(context,(HWND)jwin,(long)jr1,(long)jr2)) ;
   }
