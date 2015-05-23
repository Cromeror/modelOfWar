

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

/**
 *
 * @author Gustavo Pacheco
 */
public class Setting {

    private float EIT;

    private float EST;

    private float ESH;

    private float EITVH;
    private float T;
    private float IT;
    private float H;
    private float TL;
    private float ITL;
    private float HL;

    private final Properties properties;

    private static Setting instance;

    public static boolean savedSetting;

    private Setting() throws IOException {
        this.properties = new Properties();
        load();
    }

    public static Setting getInstance() throws IOException {
        if (instance == null) {
            instance = new Setting();
        }
        return instance;
    }

    public float getT() {
        return T;
    }

    public void setT(float T) {
        this.T = T;
    }

    public float getIT() {
        return IT;
    }

    public void setIT(float IT) {
        this.IT = IT;
    }

    public float getH() {
        return H;
    }

    public void setH(float H) {
        this.H = H;
    }

    public float getTL() {
        return TL;
    }

    public void setTL(float TL) {
        this.TL = TL;
    }

    public float getITL() {
        return ITL;
    }

    public void setITL(float ITL) {
        this.ITL = ITL;
    }

    public float getHL() {
        return HL;
    }

    public void setHL(float HL) {
        this.HL = HL;
    }

    public float getEIT() {
        return EIT;
    }

    public void setEIT(float EIT) {
        this.EIT = EIT;
    }

    public float getEST() {
        return EST;
    }

    public void setEST(float EST) {
        this.EST = EST;
    }

    public float getESH() {
        return ESH;
    }

    public void setESH(float ESH) {
        this.ESH = ESH;
    }

    public float getEITVH() {
        return EITVH;
    }

    public void setEITVH(float EITVH) {
        this.EITVH = EITVH;
    }

    private void load() throws IOException {
        properties.load(getClass().getResourceAsStream("setting.properties"));
        //cargamos las propiedades
        this.EIT = Float.parseFloat(properties.getProperty("setting.EIT"));
        this.EST = Float.parseFloat(properties.getProperty("setting.EST"));
        this.ESH = Float.parseFloat(properties.getProperty("setting.ESH"));
        this.EITVH = Float.parseFloat(properties.getProperty("setting.EITVH"));
        this.T = Float.parseFloat(properties.getProperty("setting.T"));
        this.IT = Float.parseFloat(properties.getProperty("setting.IT"));
        this.H = Float.parseFloat(properties.getProperty("setting.H"));
        this.TL = Float.parseFloat(properties.getProperty("setting.TL"));
        this.ITL = Float.parseFloat(properties.getProperty("setting.ITL"));
        this.HL = Float.parseFloat(properties.getProperty("setting.HL"));
    }

    public void save() throws IOException {
        properties.setProperty("setting.EIT", String.valueOf(this.getEIT()));
        properties.setProperty("setting.EST", String.valueOf(this.getEST()));
        properties.setProperty("setting.ESH", String.valueOf(this.getESH()));
        properties.setProperty("setting.EITVH", String.valueOf(this.getEITVH()));
        properties.setProperty("setting.T", String.valueOf(this.getEITVH()));
        properties.setProperty("setting.IT", String.valueOf(this.getEITVH()));
        properties.setProperty("setting.H", String.valueOf(this.getEITVH()));
        properties.setProperty("setting.TL", String.valueOf(this.getEITVH()));
        properties.setProperty("setting.ITL", String.valueOf(this.getEITVH()));
        properties.setProperty("setting.HL", String.valueOf(this.getEITVH()));
        //guardamos el archivo propiedades
        String uri = getClass().getResource("setting.properties").getFile().replaceAll("%20", " ");
        properties.store(new FileOutputStream(uri), null);
    }

    @Override
    public String toString() {
        return "Setting{" + "EIT=" + EIT + ", EST="
                + EST + ", ESH=" + ESH + ", EITVH=" + EITVH
                + ", properties=" + properties + '}';
    }

}
