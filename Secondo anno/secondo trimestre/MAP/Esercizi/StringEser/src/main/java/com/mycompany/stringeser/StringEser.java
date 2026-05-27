/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.stringeser;

import static java.lang.Math.pow;
import static java.lang.Math.random;
import java.util.Scanner;

/**
 *
 * @author amilo
 */
public class StringEser {

    public static void main(String[] args) {
        String stringa1 = new String("2.5");
        String stringa2 = new String("4.7");
               
        double d1,d2=0;
        Integer MAX = 100;
        Integer MAXLunghezzaEmail = 365;
        int posizione = 0;
                
        // Conversione stringa in numero
        d1=Double.parseDouble(stringa1);
        d2=Double.parseDouble(stringa2);
        
        // String format
        System.out.format("La somma dei due valori e': %.3f",d1+d2);
        
        // Elevamento a potenza
        System.out.format("\nLa potenza dei due numeri precedenti dove %.2f e' la base e %.2f e' l'esponente: %.3f\n", d1,d2, pow(d1,d2));
        
        // Random es.
        if(d1<Integer.MAX_VALUE){
            double random_number=Math.random()*100;
            System.out.println(random_number);
            if(random_number>d1)
                System.out.println("True");
        }
        else
            System.out.println("False");
        
        // Espressione regolare email
        Scanner sc = new Scanner(System.in);
        System.out.println("Inserisci il tuo indirizzo email: ");
        String email = new String(sc.nextLine());
        
        if(email.length() <= MAXLunghezzaEmail && email.length()>0){
            String regex = "[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}";
            boolean isValida = email.matches(regex);
            System.out.println(isValida); // Vediamo se la regex è rispettata avendo true o false come output
        }
        else
            System.out.println("Email errata");
    }
}
