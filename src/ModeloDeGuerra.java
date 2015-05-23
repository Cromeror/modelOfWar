

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Cristobal
 */
public class ModeloDeGuerra {

    private int timeSimulation = 0;
    private String runName;
    private static ModeloDeGuerra instance = null;

    private ModeloDeGuerra() {
        
    }
    
    public static ModeloDeGuerra getInstance(){
        if (instance == null) {
            instance = new ModeloDeGuerra();
        }
        return instance;
    }

    public int getTimeSimulation() {
        return timeSimulation;
    }

    public void setTimeSimulation(int timeSimulation) {
        this.timeSimulation = timeSimulation;
    }

    public String getRunName() {
        return runName;
    }

    public void setRunName(String runName) {
        this.runName = runName;
    }
    
    
    public void getT(float[] T_Y){
        Vensim.get_data(runName+".vdf", "T", "Time", T_Y, new float[10], 10);
    }
    public void getIT(float[] IT_Y){
        Vensim.get_data(runName+".vdf", "IT", "Time", IT_Y, new float[10], 10);
    }
    public void getH(float[] H_Y){
        Vensim.get_data(runName+".vdf", "H", "Time", H_Y, new float[10], 10);
    }
    public void getEIT(float[] EIT_Y){
        Vensim.get_data(runName+".vdf", "EIT", "Time", EIT_Y, new float[10], 10);
    }
    public void getTL(float[] TL_Y){
        Vensim.get_data(runName+".vdf", "TL", "Time", TL_Y, new float[10], 10);
    }
    public void getEST(float[] EST_Y){
        Vensim.get_data(runName+".vdf", "EST", "Time", EST_Y, new float[10], 10);
    }
    public void getESH(float[] ESH_Y){
        Vensim.get_data(runName+".vdf", "ESH", "Time", ESH_Y, new float[10], 10);
    }
    public void getITL(float[] ITL_Y){
        Vensim.get_data(runName+".vdf", "ITL", "Time", ITL_Y, new float[10], 10);
    }
    public void getEITVH(float[] EITVH_Y){
        Vensim.get_data(runName+".vdf", "EITVH", "Time", EITVH_Y, new float[10], 10);
    }
    public void getHL(float[] HL_Y){
        Vensim.get_data(runName+".vdf", "HL", "Time", HL_Y, new float[10], 10);
    }
    
    public void setT(float value){
        Vensim.command("SIMULATE>SETVAL|T="+value);
    }
    public void setEIT(float value){
        Vensim.command("SIMULATE>SETVAL|EIT="+value);
    }
    public void setIT(float value){
        Vensim.command("SIMULATE>SETVAL|IT="+value);
    }
    public void setEST(float value){
        Vensim.command("SIMULATE>SETVAL|EST="+value);
    }
    public void setESH(float value){
        Vensim.command("SIMULATE>SETVAL|ESH="+value);
    }
    public void setH(float value){
        Vensim.command("SIMULATE>SETVAL|H="+value);
    }
    public void setEITVH(float value){
        Vensim.command("SIMULATE>SETVAL|EITVH="+value);
    }
    
    
    public void run(){
        Connection.run(runName);
    }
}
