package modelWar.setting;

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

    private int EIT;

    private int EST;

    private int ESH;

    private int EITVH;

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

    public int getEIT() {
        return EIT;
    }

    public void setEIT(int EIT) {
        this.EIT = EIT;
    }

    public int getEST() {
        return EST;
    }

    public void setEST(int averageTimeOut) {
        this.EST = averageTimeOut;
    }

    public int getESH() {
        return ESH;
    }

    public void setESH(int servers) {
        this.ESH = servers;
    }

    public int getEITVH() {
        return EITVH;
    }

    public void setEITVH(int rows) {
        this.EITVH = rows;
    }

    private void load() throws IOException {
        properties.load(getClass().getResourceAsStream("setting.properties"));
        //cargamos las propiedades
        this.EIT = Integer.parseInt(properties.getProperty("setting.EIT"));
        this.EST = Integer.parseInt(properties.getProperty("setting.EST"));
        this.ESH = Integer.parseInt(properties.getProperty("setting.ESH"));
        this.EITVH = Integer.parseInt(properties.getProperty("setting.EITVH"));
    }

    public void save() throws IOException {
        properties.setProperty("setting.EIT", String.valueOf(this.getEIT()));
        properties.setProperty("setting.EST", String.valueOf(this.getEST()));
        properties.setProperty("setting.ESH", String.valueOf(this.getESH()));
        properties.setProperty("setting.EITVH", String.valueOf(this.getEITVH()));
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
