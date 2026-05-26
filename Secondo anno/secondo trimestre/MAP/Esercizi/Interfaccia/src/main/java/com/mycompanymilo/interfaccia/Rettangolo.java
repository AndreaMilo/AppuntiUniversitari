/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompanymilo.interfaccia;

/**
 *
 * @author Utente
 */

//Rettangolo
public class Rettangolo extends FiguraComp {
    public Rettangolo(double b, double h) {
        super(b, h); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/OverriddenMethodBody
    }
    
    @Override
    public double area(){
        return dim1*dim2;
    }
}

