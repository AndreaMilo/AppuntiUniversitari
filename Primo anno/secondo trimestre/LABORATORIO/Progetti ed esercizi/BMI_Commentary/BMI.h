/* Questo file è parte di un progetto che ci permetterà tramite funzioni di
 * calcolare la media di 2 nuermi naturali e verificare il corretto funzionamento
 * calcolo del BMI tra varie condizioni di peso e verifica del corretto funzionamento
 * verifica dell'esame superato e verifica del corretto funzionamento
 * 
 * i corretti funzionamenti saranno controllati con fase di test con xUnity
 * 
 * void BMI(float peso, float altezza);
 * void CalcoloMedia(int a, int b);
 * void Esamesuperato(int voto);
 * 
 * Autore: Andrea Milo
 * Data: 2025-05-06
 * Versione: 1.0
*/

#ifndef BMIT_H
#define BMIT_H

float CalcoloBMI(float, float);
float CalcoloMedia(int, int);
int Esamesuperato(int);

#endif // BMIT_H