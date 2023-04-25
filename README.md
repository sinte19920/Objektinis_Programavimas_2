# Objektinis_Programavimas

## v.05 yra patobulinta v.04 versija. 
Nebuvo daug kas pakeista, tik pasitelkiama 'vector', 'deque' ir 'list' pagalba, norint patikrinti programos veikimo spartą. Paleidus programą, reikia pasirinkti, su kurio iš 3 konteinerių norima dirbti.


## Programos sparta:

**VECTOR / vidurkis**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  1 000           |  0.017005s    |  0.005989s    |  0.000266    |  0.020997s     |  0.029998s   |
|  10 000          |  0.181041s    |  0.049003s    |  0.184041s   |  0.184041s     |  0.275053s   |
|  100 000         |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  1 000 000       |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |
|  10 000 000      |               |               |              |                |              |

**VECTOR / mediana**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  1 000           |  0.017005s    |  0.005989s    |  0.000266    |  0.020997s     |  0.029998s   |
|  10 000          |  0.181041s    |  0.049003s    |  0.184041s   |  0.184041s     |  0.275053s   |
|  100 000         |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  1 000 000       |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |
|  10 000 000      |               |               |              |                |              |

**LIST / vidurkis**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+) |  Spausdinimas (-) |    Viso     |
|------------------|---------------|---------------|--------------|-------------------|-------------------|-------------|
|  1 000           |  0.04s        |  0.02s        |  0.01s       |  0.01s            |                   | 0.0         |
|  10 000          |  0.26s        |  0.13s        |  0.184041s   |  0.184041s        |                   | 0.275053s   |
|  100 000         |  2.36s        |  1.41s        |  0.488099s   |  1.83541s         |                   | 2.86863s    |
|  1 000 000       |  20.71s       |  15.25s       |  4.68205s    |  18.5489s         |                   | 29.3834s    |

**LIST / mediana**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  1 000           |  0.017005s    |  0.005989s    |  0.000266    |  0.020997s     |  0.029998s   |
|  10 000          |  0.181041s    |  0.049003s    |  0.184041s   |  0.184041s     |  0.275053s   |
|  100 000         |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  1 000 000       |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |

**DEQUE / vidurkis**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  1 000           |  0.017005s    |  0.005989s    |  0.000266    |  0.020997s     |  0.029998s   |
|  10 000          |  0.181041s    |  0.049003s    |  0.184041s   |  0.184041s     |  0.275053s   |
|  100 000         |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  1 000 000       |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |

**DEQUE / mediana**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  1 000           |  0.017005s    |  0.005989s    |  0.000266    |  0.020997s     |  0.029998s   |
|  10 000          |  0.181041s    |  0.049003s    |  0.184041s   |  0.184041s     |  0.275053s   |
|  100 000         |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  1 000 000       |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |
