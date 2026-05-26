/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompanymilo.interfaccia;

/**
 *
 * @author Utente
 */
public abstract class FiguraComp implements Figura, Comparable{
    // Istanza variabili
    protected double dim1;
    protected double dim2;
    
    // Istanziare i metodi
    public FiguraComp(double val1,double val2){
        this.dim1=val1;
        this.dim2=val2;
    }
    
    @Override
    public int compareTo(Object o){
        double confronto=0;
        
        FiguraComp casting_object = (FiguraComp) o; // casting degli oggetti passati in FiguraComp
        confronto=this.area(); // area della figura attuale
        casting_object.area(); // area della figura passata
        if(confronto==casting_object.area())
            return 0;
        else if(confronto>=casting_object.area())
            return 1;
        else
            return -1;
    }
    
    @Override
    public boolean equals(Object o){
        double confronto=0;
        
        FiguraComp casting_object = (FiguraComp) o; // casting degli oggetti passati in FiguraComp
        confronto=this.area(); // area della figura attuale
        casting_object.area(); // area della figura passata
        if(confronto==casting_object.area())
            return true;
        else return false;
}
    
    @Override
    public String toString() {
        return "L'Area e': " + area();
    }
}








