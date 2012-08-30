#
# Makefile for letter of reference for Annie Cruz
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

checkout:
	co -l $(latex_source) $(makefile)

checkin:
	ci -u $(latex_source) $(makefile)

checkpoint:
	make checkin && make checkout

spell:
	$(aspell_cmd) $(latex_source)

clean:
	rm -f *.aux *.bbl *.blg *.idx *.ilg *.ind *.log *.dvi *.bak $(consolidated_bibtex_file) .pdf

allclean: clean
	rm -f $(pdf)

