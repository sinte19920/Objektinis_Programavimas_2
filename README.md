# v1.1

Nuo šios versijos jau pradėta naudoti klasė "Studentas". 

## Programos sparta, naudojant skiringus flags (studentas gauna po 3 pažymius):

### -o1
|  Įrašų skaičius  |  Rūšiavimas   |   Spausinimas >=5.0  |   Spausinimas <5.0   |
|------------------|---------------|----------------------|----------------------|
|    1 000         |  0.001s       |   0.016s             |   0.016s             |
|    10 000        |  0.063s       |   0.116s             |   0.122s             |
|    100 000       |  0.786s       |   1.118s             |   0.949s             |
|    1 000 000     |  9.893s       |   8.652s             |   8.668s             |

### -o2
|  Įrašų skaičius  |  rūšiavimas   |   spausinimas >=5.0  |   spausinimas <5.0   |
|------------------|---------------|----------------------|----------------------|
|    1 000         |  0.001s       |   0.020s             |   0.016s             |
|    10 000        |  0.053s       |   0.132s             |   0.138s             |
|    100 000       |  0.802s       |   1.203s             |   1.226s             |
|    1 000 000     |  9.685s       |   8.730s             |   8.875s             |

### -o3
|  Įrašų skaičius  |  rūšiavimas   |   spausinimas >=5.0  |   spausinimas <5.0   |
|------------------|---------------|----------------------|----------------------|
|    1 000         |  0.010s       |   0.016s             |   0.014s             |
|    10 000        |  0.085s       |   0.163s             |   0.154s             |
|    100 000       |  0.740s       |   1.219s             |   0.998s             |
|    1 000 000     |  9.324s       |   9.661s             |   8.798s             |

Lyginant su senesne (v1.0) versija, ženkliai pagreitėjo tik darbas su 1 000 000 studentų duomenimis ir, šiek tiek mažiau, su 100 000 studentų duomenimis.
Studentų rūšiavimas su 1 000 000 pagreitėjo apie 25.3s, o 100 000 pagreitėjo apie 2.1s.
Senesnėje versijoje buvo naudojami std::vector, std::list ir std::deque konteineriai, pasirinkau palyginimui vector, nes naujausiose versijose programa pasirinkta realizuoti tik su std::vector.

### v1.0 (nurodytas rūšiavimo užtruktas laikas)
|  Įrašų skaičius  |  std::vector  |
|------------------|---------------|
|    1 000         |  0.020s       |
|    10 000        |  0.223s       |
|    100 000       |  2.749s       |
|    1 000 000     |  34.626s      |
