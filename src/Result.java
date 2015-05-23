/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import com.sun.imageio.plugins.jpeg.JPEG;

/**
 *
 * @author Karen
 */
public class Result {

    private String runName;
    private float T_X[];
    private float IT_X[];
    private float H_X[];
    private float TL_X[];
    private float ITL_X[];
    private float HL_X[];
    //Son los arrays que guardaran los datos del eje Y
    private float T_Y[];
    private float IT_Y[];
    private float H_Y[];
    private float TL_Y[];
    private float ITL_Y[];
    private float HL_Y[];
    //Tasas que se declaran con una sola posicion por poseer un solo dato
    private float EIT[];
    private float EST[];
    private float ESH[];
    private float EITVH[];

    public Result(String runName) {
        
        this.runName = runName;
        T_X = new float[10];
        IT_X = new float[10];
        H_X = new float[10];
        TL_X = new float[10];
        ITL_X = new float[10];
        HL_X = new float[10];
        T_Y = new float[10];
        IT_Y = new float[10];
        H_Y = new float[10];
        TL_Y = new float[10];
        ITL_Y = new float[10];
        HL_Y = new float[10];
        EIT = new float[1];
        EST = new float[1];
        ESH = new float[1];
        EITVH = new float[1];
    }

    public float[] getT_X() {
        return T_X;
    }

    public float[] getIT_X() {
        return IT_X;
    }

    public float[] getH_X() {
        return H_X;
    }

    public float[] getTL_X() {
        return TL_X;
    }

    public float[] getITL_X() {
        return ITL_X;
    }

    public float[] getHL_X() {
        return HL_X;
    }

    public float[] getT_Y() {
        return T_Y;
    }

    public float[] getIT_Y() {
        return IT_Y;
    }

    public float[] getH_Y() {
        return H_Y;
    }

    public float[] getTL_Y() {
        return TL_Y;
    }

    public float[] getITL_Y() {
        return ITL_Y;
    }

    public float[] getHL_Y() {
        return HL_Y;
    }

    public float[] getEIT() {
        return EIT;
    }

    public float[] getEST() {
        return EST;
    }

    public float[] getESH() {
        return ESH;
    }

    public float[] getEITVH() {
        return EITVH;
    }

    public String getRunName() {
        return runName;
    }

}
