#
# Makefile for letter to Professor Knuth
#

target = letter_to_prof_knuth

#
# Source code files
#

latex_source = $(target).tex
makefile = Makefile

#
# Locations of needed files
#

home = /home/rjl
consolidated_bibtex_file = consolidated_bibtex_file.bib

#
# Temporary Files
#

logfile = $(target).log
pdf = $(target).pdf

#
# Executable Commands
#

latex_cmd = pdflatex
aspell_cmd = aspell --lang=en_GB check

#
# Default makefile target
#

documentation = README.md

#
# Note: make requires that we set the value of a variable OUTSIDE any rules.
#

timestamp = `date +%Y%m%d.%H%M`

all: $(pdf)

#
# Helper makefile targets
#

$(pdf): $(latex_source) $(consolidated_bibtex_file) $(makefile)
	$(latex_cmd) $(target)
	if (grep "Warning" $(target).blg > /dev/null ) then false ; fi
	while ( $(latex_cmd) $(latex_source) ; \
		grep "Rerun to get cross" $(logfile) > /dev/null ) do true ; \
	done

$(consolidated_bibtex_file):
	cp ../bibtex/consolidated_bibtex_source.bib ./$(consolidated_bibtex_file)

vi:
	vi $(latex_source)

edit: vi

notes:
	(cd ../notes && make vi)

quotes:
	(cd ../notes && make quotes)

bibtex:
	(cd ../bibtex && make vi)

spell:
	aspell --lang=en_GB -t check $(latex_source)
	$(aspell_cmd) $(documentation)

clean:
	rm -f *.aux *.bbl *.blg *.idx *.ilg *.ind *.log *.dvi *.bak $(consolidated_bibtex_file) .pdf

allclean: clean
	rm -f $(pdf) $(documentation).bak

commit:
	make clean
	git add .
	git commit -am "commit from Makefile $(timestamp)"
	git pull --rebase
	git push

readme:
	vi $(documentation)

