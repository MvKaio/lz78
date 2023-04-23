# lz78

This repository provides a simple implementation of the [lz78 algorithm](https://en.wikipedia.org/wiki/LZ77_and_LZ78),
a lossless data compression algorithm that was created in 1978 by Abraham Lempel and Jacob Ziv. The project was developed as an [assignment](https://github.com/MvKaio/lz78/blob/main/inputs/specification/tp1.txt) for a course on algorithms @ UFMG, 
with the goal of exploring an application of the trie data structure, which is a useful tool in string algorithms that involve searching for patterns
within a text, such as in string matching.

## How to use?


| **Name**              | a.txt    | random.txt | alphabet.txt | aaa.txt  | paper5   | paper4  | paper6   | progc   | paper3   | paper1   | paper2   | progp   | news    | bib     | progl   | book2   | xargs.1  | grammar.lsp | fields.c | cp.html  | asyoulik.txt | alice29.txt | plrabn12.txt | lcet10.txt | world192.txt | bible.txt | E.coli  | pi.txt  | tp1.txt       | os_lusiadas.txt | dom_casmurro.txt | constituicao1988.txt |
|-----------------------|----------|------------|--------------|----------|----------|---------|----------|---------|----------|----------|----------|---------|---------|---------|---------|---------|----------|-------------|----------|----------|--------------|-------------|--------------|------------|--------------|-----------|---------|---------|---------------|-----------------|------------------|----------------------|
| **Testset**           | artificl | artificl   | artificl     | artificl | calgary  | calgary | calgary  | calgary | calgary  | calgary  | calgary  | calgary | calgary | calgary | calgary | calgary | cantrbry | cantrbry    | cantrbry | cantrbry | cantrbry     | cantrbry    | cantrbry     | cantrbry   | large        | large     | large   | misc    | specification | specification   | specification    | specification        |
| **Input Size**        | 1        | 100000     | 100000       | 100000   | 11954    | 13286   | 38105    | 39611   | 46526    | 53161    | 82199    | 49379   | 377109  | 111261  | 71646   | 610856  | 4227     | 3721        | 11150    | 24603    | 125179       | 152089      | 481861       | 426754     | 2473400      | 4047392   | 4638690 | 1000000 | 6550          | 344538          | 409610           | 651790               |
| **Compressed Size**   | 10       | 170945     | 11340        | 2235     | 17050    | 18245   | 45745    | 47295   | 54525    | 60835    | 86685    | 49060   | 367175  | 107295  | 68120   | 512560  | 6720     | 5355        | 13925    | 28425    | 127955       | 145460      | 423550       | 360420     | 1566530      | 2454030   | 2455550 | 916445  | 9980          | 325380          | 370455           | 445245               |
| **Compression Ratio** | 0.1      | 0.584983   | 8.81834      | 44.7427  | 0.701114 | 0.7282  | 0.832987 | 0.83753 | 0.853297 | 0.873856 | 0.948249 | 1.0065  | 1.02706 | 1.03696 | 1.05176 | 1.19177 | 0.629018 | 0.694865    | 0.800718 | 0.865541 | 0.978305     | 1.04557     | 1.13767      | 1.18405    | 1.5789       | 1.64928   | 1.88906 | 1.09117 | 0.656313      | 1.05888         | 1.10569          | 1.46389              |

