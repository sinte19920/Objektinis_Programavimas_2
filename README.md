# V1.0

Nuo šios versijos yra pradedama naudoti makefile. Didžiausi pakeitimai (lyginant su v.05), kad yra 2 strategijos: pirma, kurioje studentai yra išskirstomi į du skirtingus vektorius ("islaike" ir "neislaike"), nors toks rūšiavimo būdas buvo naudojamas nuo ankstesnių versijų, o antra, kurioje studentai, gavę galutinį pažymį 5 ir daugiau yra paliekami "studentai" vektoriuje, o likę pašalinami (dirbama su tuo pačiu vektorium). Yra kiekvieną kartą paklausiama, kurią strategija vartotojas nori panaudoti.

### Studentų rūšiavimo į grupes sparta:

**Pirma strategija**
|  Įrašų skaičius  |  std::vector  |   std::list   |   std:deque   |
|------------------|---------------|---------------|---------------|
|    1 000         |  0.020s       |   0.013s      |   0.019s      |
|    10 000        |  0.223s       |   0.165s      |   0.219s      |
|    100 000       |  2.749s       |   2.185s      |   2.925s      |
|    1 000 000     |  34.626s      |   25.726s     |   34.346s     |

**Antra strategija**
|  Įrašų skaičius  |  std::vector  |   std::list   |   std:deque   |
|------------------|---------------|---------------|---------------|
|    1 000         |  0.009s       |   0.009s      |   0.010s      |
|    10 000        |  0.102s       |   0.102s      |   0.116s      |
|    100 000       |  1.260s       |   1.048s      |   1.429s      |
|    1 000 000     |  15.825s      |   11.257s     |   16.815s     |

# Objektinis_Programavimas

## v.05 yra patobulinta v.04 versija. 
Nebuvo daug kas pakeista, tik pasitelkiama 'vector', 'deque' ir 'list' pagalba, norint patikrinti programos veikimo spartą. Leidžiant programą su komandine eilute reikia pasirinkti, su kurio iš 3 konteinerių norima dirbti.

**Programos paleidimui reikalingos komandinės eilutės:**
- g++ -o programa main.cpp funkcijos.cpp funkcijos.h
- g++ -o programa main_list.cpp funkcijos.cpp funkcijos.h
- g++ -o programa main_deque.cpp funkcijos.cpp funkcijos.h

## Programos sparta:

**VECTOR / vidurkis**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+) |  Spausdinimas (-) |
|------------------|---------------|---------------|--------------|-------------------|-------------------|
|  1 000           |  0.03s        |  0.02s        |  0.02s       |  0.01s            |  0.01s            |
|  10 000          |  0.26s        |  0.17s        |  0.24s       |  0.10s            |  0.12s            |
|  100 000         |  2.91s        |  1.58s        |  3.20s       |  1.20s            |  0.85s            |
|  1 000 000       |  18.80s       |  14.95s       |  34.76s      |  9.01s            |  8.60s            |
|  10 000 000      |  189.32s      |  179.66s      |  160.01s     |  132.45s          |  130.34s          |

**VECTOR / mediana**

|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+) |  Spausdinimas (-) |
|------------------|---------------|---------------|--------------|-------------------|-------------------|
|  1 000           |  0.03s        |  0.02s        |  0.02s       |  0.01s            |  0.01s            |
|  10 000          |  0.30s        |  0.16s        |  0.24s       |  0.06s            |  0.17s            |
|  100 000         |  2.68s        |  1.57s        |  3.37s       |  0.67s            |  1.35s            |
|  1 000 000       |  19.54s       |  14.96s       |  36.20s      |  4.77s            |  12.82s           |
|  10 000 000      |  185.82s      |  170.43s      |  134.65s     |  115.59s          |  117.26s          |

**LIST / vidurkis**

|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+) |  Spausdinimas (-) |
|------------------|---------------|---------------|--------------|-------------------|-------------------|
|  1 000           |  0.04s        |  0.02s        |  0.01s       |  0.01s            |  0.01s            |
|  10 000          |  0.26s        |  0.13s        |  0.17s       |  0.13s            |  0.10s            |
|  100 000         |  2.36s        |  1.41s        |  2.44s       |  1.12s            |  0.99s            |
|  1 000 000       |  20.71s       |  15.25s       |  25.61s      |  9.85s            |  9.82s            |
|  10 000 000      |  205.78s      |  194.04s      |  215.71s     |  172.09s          |  174.52s          |


**LIST / mediana**

|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+)  | Spausdinimas (-) |
|------------------|---------------|---------------|--------------|--------------------|------------------|
|  1 000           |  0.04s        |  0.03s        |  0.02s       |  0.01s             | 0.02s            |
|  10 000          |  0.25s        |  0.18s        |  0.21s       |  0.08s             | 0.16s            |
|  100 000         |  2.25s        |  1.51s        |  2.55s       |  0.52s             | 1.42s            | 
|  1 000 000       |  20.26s       |  12.26s       |  25.20s      |  4.46s             | 13.50s           |
|  10 000 000      |  189.07s      |  145.56s      |  162.43s     |  102.30s           | 100.98s          |

**DEQUE / vidurkis**

|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+)  | Spausdinimas (-)|
|------------------|---------------|---------------|--------------|--------------------|-----------------|
|  1 000           |  0.03s        |  0.01s        |  0.01s       |  0.01s             |  0.01s          |
|  10 000          |  0.33s        |  0.12s        |  0.21s       |  0.09s             |  0.09s          |
|  100 000         |  2.15s        |  1.47s        |  3.46s       |  1.02s             |  0.95s          |
|  1 000 000       |  19.39s       |  14.65s       |  34.82s      |  8.79s             |  8.49s          |
|  10 000 000      |  187.23s      |  132.35s      |  200.91s     |  125.69s           |  142.61s        |

**DEQUE / mediana**

|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas (+) |  Spausdinimas (-) |
|------------------|---------------|---------------|--------------|-------------------|-------------------|
|  1 000           |  0.03s        |  0.01s        |  0.01s       |  0.00s            |  0.01s            |
|  10 000          |  0.23s        |  0.13s        |  0.23s       |  0.05s            |  0.13s            |
|  100 000         |  2.17s        |  1.46s        |  3.32s       |  0.45s            |  1.35s            |
|  1 000 000       |  19.77s       |  15.65s       |  35.62s      |  4.53s            |  13.06s           |
|  10 000 000      |  205.30s      |  205.73s      |  253.95s     |  215.26s          |  199.30s          |

## Sistemos parametrai:

 **Procesorius** Intel(R) Core(TM) i5-3230M CPU @ 2.60GHz
 **RAM** 4,0 GB DDR3 Single-Channel 800MHz
 **SSD** HP SSD S700 500GB

# v.04

## v.04 yra patobulinta v.03 versija. 
Papildomai pridėtas failų generatorius, kuris sugeneruoja studentų failus su jų pažymiais, po to šie sugeneruoti failai panaudojami tolesnės uždoties atlikimui. 

## Papildomai pridėtas studentų surūšiavimas į dvi grupes pagal galutinį rezultatą:
studentai, kurie turi galutinį pažymį mažesnį, negu 5 ir kita grupė studentų, kurie turi 5 arba aukščiau. Surūšiuoti studentai ir jų galutiniai pažymiai yra išvedami į du naujus failus (galutinis rezultatas).

## Papildomai yra vykdoma programos veikimo greičio analizė:
1. failų sukūrimas
2. duomenų nuskaitymas iš failo
3. studentų rūšiavimas į dvi kategorijas
4. surūšiuotų studentų išvedimas į du naujus failus
5. visos programos veikimas

# v0.3 

## visas kodas išskirstytas į skirtingus failus: 
'main.cpp' - pagrindinė programos dalis, 'Mylib.h' - failas, kuriame saugomos visos bibliotekos ir jų pagrindinės funkcijos, 'funkcijos.h' - antraštinis failas, kuriame laikoma studento struktūra ir antraštės, 'funkcijos.cpp' - laikomi funkcijų aprašymai. 
Įtrauktas 1 išimčių valdymas.

# v.02

## Kodas yra labai panašus į v.01, nors ir yra keli papildomi veiksmai. 
'v0.2.cpp' kode yra nuskaitomi studento duomenys iš failo, pačioje pradžioje jau yra paprašoma vartotojo nurodyti pageidautiną pavadinimą. Nuskaityti duomenys yra apdorojami kaip ir pirmoje versijoje, tik jau vartotojas gauna galimybę pasirinkti ar norima, kad duomenys būtų surikiuojami pagal vardą arba pavardę. 
## Po pasirinkimo duomenys yra surikiuojami ir išspausdinami "rezultatai.txt" tekstiniame faile.
Taip pat yra papildomas laiko apskaičiavimo kodas: panaudota 'chrono' biblioteka, todėl galima sužinoti, kiek laiko (sekundės ir milisekundės) užtruko išspausdinti rezultatus.

# V.01

## Kodas nuskaito studento duomenis (vardas, pavardė, pažymiai) ir jie išsaugomi į dinaminius masyvus (v0.1_masyvai.cpp) arba vektorius (v0.1_vektoriai.cpp). 

Išsaugojęs duomenis, apskaičiuojamas galutinis studento pažymys su mediana arba vidurkiu, priklausomai nuo vartotojo poreikio. 
Taip pat kode galima pasirinkti, ar sugeneruoti atsitiktinius pažymius. Kodą galima naudoti net ir tuo metu, jeigu nežinomas studentų ir pažymių skaičius. Kiekvieną kartą įvesties metu, įvedus netinkamą įvestį, prašoma pakartoti, kol ji bus teisinga (išimtis taikoma tik tuo metu, kai pažymių skaičius nežinomas ir kaip tik prašoma klaidinga įvestis, norint parodyti, kad pažymių tam studentui daugiau nebebus priskirta).

## Apskaičiuojamas galutinis pažymys pagal šias formules: 
Galutinis = 0.4 * vidurkis + 0.6 * egzaminas 
arba 
Galutinis = 0.4 * mediana + 0.6 * egzaminas. 

O galutiniame rezultate išvedami šie duomenys: studento vardas, pavardė ir galutinis pažymys.
