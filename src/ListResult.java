/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.ArrayList;

/**
 *
 * @author familia
 */
public class ListResult extends ArrayList<Result> {

    private Result initial;
    private static ListResult instance = null;

    private ListResult() {
    }

    public static ListResult getInstance() {
        if (instance == null) {
            instance = new ListResult();
        }
        return instance;
    }
}
