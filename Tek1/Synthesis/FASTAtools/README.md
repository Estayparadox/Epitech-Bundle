# FASTAtools
This program read a FASTA file and write the DNA sequences, while complying with the FASTA format.

## What's that ?
This program read a FASTA file from the standard input, and write the DNA sequences to the standard output, while complying
with the FASTA format.

## FASTA ?
FASTA is a file format often used in bioinformatics. It consists in matching identifiers and DNA sequencies.
The identifier is declared on a line starting with the > symbol. The following filled lines, which do not start with >,
contain the DNA sequence.

### Example:
```
>seq1
ATATGCAGAGTTAGT
>seq2
catCATGCC TADGACGAA
GAGATGCTTTGAATGGRAATGAA
```

## How to use it ?
```
USAGE:
    ./FASTAtools option [k] < FASTAfile

DESCRIPTION:
    option  1:read FASTA from the standard input, write the DNA sequences
              to the standard output.
            2:read FASTA from the standard input, write the RNA sequences
              to the standard output.
            3:read FASTA from the standard input, write the reverse complement
              to the standard output.
            4:read FASTA from the standard input, write the k-mer list
              to the standard output.
    k       size of the k-mers for option 4
```
