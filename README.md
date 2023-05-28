# v1.1

Nuo šios versijos jau pradėta naudoti klasė "Studentas". Programos realizavimui yra pasitelkta kelių flags pagalba: -O1, -O2 ir -O3.

## Programos sparta, naudojant skiringus flags (studentas gauna po 3 pažymius):

### -o1
|  Įrašų skaičius  |  Rūšiavimas   |   Spausinimas >=5.0  |   Spausinimas <5.0   |
|------------------|---------------|----------------------|----------------------|
|    1 000         |  0.001s       |   0.016s             |   0.016s             |
|    10 000        |  0.051s       |   0.111s             |   0.100s             |
|    100 000       |  0.678s       |   0.998s             |   1.056s             |
|    1 000 000     |  7.988s       |   8.038s             |   7.776s             |

### -o2
|  Įrašų skaičius  |  rūšiavimas   |   spausinimas >=5.0  |   spausinimas <5.0   |
|------------------|---------------|----------------------|----------------------|
|    1 000         |  0.001s       |   0.020s             |   0.016s             |
|    10 000        |  0.053s       |   0.100s             |   0.085s             |
|    100 000       |  0.674s       |   1.006s             |   1.056s             |
|    1 000 000     |  8.070s       |   7.994s             |   7.779s             |

### -o3
|  Įrašų skaičius  |  rūšiavimas   |   spausinimas >=5.0  |   spausinimas <5.0   |
|------------------|---------------|----------------------|----------------------|
|    1 000         |  0.016s       |   0.016s             |   0.016s             |
|    10 000        |  0.052s       |   0.117s             |   0.100s             |
|    100 000       |  0.665s       |   0.892s             |   1.148s             |
|    1 000 000     |  8.069s       |   7.994s             |   7.637s             |

Lyginant su senesne (v1.0) versija, ženkliai pagreitėjo tik darbas su 1 000 000 studentų duomenimis ir, šiek tiek mažiau, su 100 000 studentų duomenimis.
Studentų rūšiavimas su 1 000 000 pagreitėjo apie 23.7s, o 100 000 pagreitėjo apie 1.8s.
Senesnėje versijoje buvo naudojami std::vector, std::list ir std::deque konteineriai, pasirinkau palyginimui vector, nes naujausiose versijose programa pasirinkta realizuoti tik su std::vector.

### v1.0 (nurodytas rūšiavimo užtruktas laikas)
|  Įrašų skaičius  |  std::vector  |
|------------------|---------------|
|    1 000         |  0.016s       |
|    10 000        |  0.201s       |
|    100 000       |  2.441s       |
|    1 000 000     |  31.732s      |
