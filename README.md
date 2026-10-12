<div align="center">

# SBMLparser

**Un parseur XML maison pour des modèles de biologie (SBML).**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/>

<sub>Projet solo · 2023</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/term-sbml-parser.png" alt="SBMLparser" width="820"/></p>

## En deux mots

Le **SBML** est le format XML qui décrit des réactions biochimiques. Le programme lit un fichier SBML sans aucune bibliothèque XML et en affiche la structure : chaque balise et ses attributs, triés.

## Ce que ça fait

- Parseur XML écrit à la main : balises, attributs, balises auto-fermantes
- Liste triée des balises et de leurs attributs
- Modèle d'exemple (cinétique enzymatique) dans [`examples/`](examples)

## Sous le capot

Le fichier est lu en entier, puis découpé en balises. Chaque nom de balise est associé à l'ensemble de ses attributs, sans doublons, avant d'être trié et affiché.

## Lancer le projet

```bash
make
./SBMLparser examples/enzyme.xml
```
