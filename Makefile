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
# default Makefile target
#

all:: $(pdf)

$(pdf): $(latex_source) $(consolidated_bibtex_file) $(makefile)
	make $(bibtex_file)
	$(latex_cmd) $(target)
	if (grep "Warning" $(target).blg > /dev/null ) then false ; fi
	while ( $(latex_cmd) $(latex_source) ; \
		grep "Rerun to get cross" $(logfile) > /dev/null ) do true ; \
	done

vi:
	vi $(latex_source)

edit: vi

spell::
	aspell --lang=en_GB -t check $(latex_source)

clean::
	rm -f *.aux *.bbl *.blg *.idx *.ilg *.ind *.log *.dvi *.bak $(consolidated_bibtex_file) .pdf

allclean: clean
	rm -f $(pdf)

include common.mk
