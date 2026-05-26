/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompanymilo.interfaccia;
import java.util.Scanner;
/**
 *
 * @author Utente
 */
public class Interfaccia {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        
        int scelta=0;
        double b=0,h=0;
        boolean bool=true;
        FiguraComp figura1=null;
        FiguraComp figura2=null;
        String stringa1, stringa2;
        
        do{
            System.out.println("Si voglia scegliere che figura analizzare: \n1 - Rettangolo\n2 - Triangolo\n3 - Quadrato ");
            scelta = sc.nextInt();
            switch(scelta){
                case 1 -> {
                    System.out.println("Inserisci la base (b): ");
                    b=sc.nextDouble();
                
                    System.out.println("e l'altezza (h): ");
                    h=sc.nextDouble();
                    
                    if(b!=h){
                        Rettangolo rett = new Rettangolo(b,h);
                        figura1=rett;
                        System.out.println(rett.toString());
                    }
                    else{
                        System.out.println("E' un quadrato allora! ");
                        Quadrato q = new Quadrato(b);
                        System.out.println(q.toString());
                    }
                    break;
                }
                case 2 -> {
                    System.out.println("Inserisci la base (b): ");
                    b=sc.nextDouble();
                
                    System.out.println("e l'altezza (h): ");
                    h=sc.nextDouble();
                
                    Triangolo tri = new Triangolo(b,h);
                    figura2=tri;
                    System.out.println(tri.toString());
                    break;
                }
                case 3 -> {
                    System.out.println("Inserisci la base: ");
                    b=sc.nextDouble();
             
                    Quadrato q = new Quadrato(b);
                    System.out.println(q.toString());
                    break;
                }
                default -> {
                    System.out.println("Non è un valore valido reinserire un numero da 1 a 3");
                    bool=false;
                    break;
                }
            }
        }while(bool);
        
        sc.nextLine();
        System.out.println("Inserisci ora 'rett' e/o 'tri' per confrontare le loro aree con il secondo inserimento successivo");
            stringa1=sc.nextLine();
            stringa2=sc.nextLine();
            System.out.println("In base a cio' che hai insierito confrontiamo se Triangolo e Rettangolo sono oggetti diversi.\nSe esce -1 l'area del primo oggetto è minore\nSe esce 1 allora è maggiore\nSe esce 0 sono pari: ");
            
            if(stringa1.equals("rett") && stringa2.equals("tri")){
                System.out.print(figura1.compareTo(figura2));
            }
            else if(stringa1.equals("tri") && stringa2.equalsIgnoreCase("rett"))
                System.out.print(figura2.compareTo(figura1));
            else if(stringa1.equals("rett") && stringa2.equalsIgnoreCase(stringa1))
                System.out.print(figura1.compareTo(figura1));
            else if(stringa1.equals("tri") && stringa2.equalsIgnoreCase(stringa1))
                System.out.print(figura2.compareTo(figura2));
            else
                System.out.println("Errore di inserimento");
        sc.close();
    }
}
