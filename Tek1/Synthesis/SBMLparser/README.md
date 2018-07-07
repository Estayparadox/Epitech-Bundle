# SBMLparser

## What's that ?
A program that print, in alphabetical order, the list of tags and attributes found in the SBML file given as argument.
## SBML ?
In order to organize huge amount of information, a XML-based format which use specialized tags for metabolic networks, was created: the SBML format.
### Example of SBML file:
```
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<sbml xmlns="http://www.sbml.org/sbml/level3/version1/core" level="3" version="1">
  <model name="Homo sapiens Glycolysis" id="Pathway146">
    <listOfCompartments>
      <compartment name="Homo sapiens, Cell, Cytosol" id="Cytosol"/>
    </listOfCompartments>
    <listOfSpecies>
      <species compartment="Cytosol" name="Adenosine diphosphate" id="Compound1034"/>
      <species compartment="Cytosol" name="Glucose 6-phosphate" id="Compound1083"/>
      <species compartment="Cytosol" name="Alpha-D-Glucose" id="Compound1851"/>
      <species compartment="Cytosol" name="Adenosine triphosphate" id="Compound414"/>
    </listOfSpecies>
    <listOfReactions>
      <reaction reversible="true" name="Hexokinase-3" id="Reaction1232">
	<listOfReactants>
	  <speciesReference stoichiometry="1" species="Compound1851"/>
	  <speciesReference stoichiometry="1" species="Compound414"/>
	</listOfReactants>
	<listOfProducts>
	  <speciesReference stoichiometry="1" species="Compound1010"/>
	  <speciesReference stoichiometry="6" species="Compound1034"/>
	</listOfProducts>
      </reaction>
    </listOfReactions>
  </model>
</sbml>
```
## How to use it ?
```
USAGE
    ./SBMLparser SBMLfile [-i ID [-e]]
    
DESCRIPTION
    SBMLfileSBML file
    -i ID id of the compartment, reaction or product to be extracted
    (ignored if uncorrect)
    -e print the equation if a reaction ID is given as argument
    (ignored otherwise)
```



    
