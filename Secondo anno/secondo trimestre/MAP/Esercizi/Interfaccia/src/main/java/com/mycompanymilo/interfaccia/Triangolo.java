/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompanymilo.interfaccia;

/**
 *
 * @author Utente
 */

// Triangolo
public class Triangolo extends FiguraComp{
    public Triangolo(double b, double h){
        super(b, h);
    }
    
    @Override
    public double area(){
        return (dim1*dim2)/2;
    }
}
