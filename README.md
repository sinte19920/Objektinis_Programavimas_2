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

# v.05 yra patobulinta v.04 versija. 
Nebuvo daug kas pakeista, tik pasitelkiama 'vector', 'deque' ir 'list' pagalba, norint patikrinti programos veikimo spartą. Leidžiant programą su komandine eilute reikia pasirinkti, su kurio iš 3 konteinerių norima dirbti.

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
