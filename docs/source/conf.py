from docutils.writers.latex2e import Babel

Babel.language_codes = {'ko':'korean', 'en':'english'}

# Configuration file for the Sphinx documentation builder.

# -- Project information

project = 'GSL'
copyright = '1996-2021 The GSL Team'
author = 'GSL Team'
title= u'GNU 과학계산 라이브러리'

release = u'2.7'
version = u'2.7'

# -- General configuration

extensions = [
    'sphinx.ext.duration',
    'sphinx.ext.doctest',
    'sphinx.ext.autodoc',
    'sphinx.ext.autosummary',
    'sphinx.ext.intersphinx',
]

source_suffix = {
    '.rst': 'restructuredtext'
}

# The master toctree document.
master_doc = 'index'

intersphinx_mapping = {
    'python': ('https://docs.python.org/3/', None),
    'sphinx': ('https://www.sphinx-doc.org/en/master/', None),
}
intersphinx_disabled_domains = ['std']

templates_path = ['_templates']
static_path = ['_static']

primary_domain = 'c'
numfig = True

# -- Options for HTML output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
html_logo = "images/logo_design.svg"
html_theme_options = {
    'logo_only': True,
    'display_version': False,
}

htmlhelp_basename = 'GSLdoc'

# -- Options for LaTex output--------------------------------------
latex_engine = 'xelatex'

my_preamble = r'''
    \usepackage{svg}                            
    \usepackage{afterpage}                      
    \usepackage[pagecolor=none]{pagecolor}      
    \usepackage{tikz}                           
    \usepackage{tikzpagenodes}                   
    \usepackage{fix-cm}

    \definecolor{coverbackground}{RGB}{209, 198, 161} 
    \definecolor{coverband}{RGB}{239, 190, 84}

    '''

my_font_setting =r'''
    \setmainfont{Noto Serif CJK KR}
    \setsansfont{Noto Sans CJK KR}
    \setmonofont{Noto Sans Mono CJK KR}
    '''

my_cover_design = r'''
    \newpage
    \pagecolor{coverbackground}\afterpage{\nopagecolor}

    \begin{tikzpicture}[remember picture,overlay,shift={(current page.north west)}]
        \fill[coverband,yshift=-120mm] rectangle(\paperwidth,85mm);
    \end{tikzpicture}

    \vspace{-0.5cm}\hspace{4.5cm}\includesvg[width=0.6\textwidth]{A_Slick_GNU_Logo.svg}

    \begin{textblock*}{5cm}(15cm,6.4cm) % {block width} (coords) 
        \raggedleft \huge\textbf{과학계산}
    \end{textblock*}

    \begin{textblock*}{10cm}(10cm,7.8cm)
        \raggedleft\Huge\textbf{라이브러리}\\
        \fontsize{35}{60}\selectfont \textbf{사용 설명서}
    \end{textblock*}

    \newpage
    \sphinxmaketitle
    '''

my_title = my_cover_design 

my_latex_authors = 'Mark Galassi \\\\ \
                    Jim Davies \\\\ \
                    James Theiler \\\\ \
                    Brian Gough \\\\ \
                    Gerard Jungman \\\\ \
                    Patrick Alken \\\\ \
                    Michael Booth \\\\ \
                    Fabrice Rossi \\\\ \
                    Rhys Ulerich'



latex_elements = {
    'papersize': 'a4papaer',
    'pointsize': '10pt',
    'preamble': my_preamble,
    'fontpkg': my_font_setting,
    'releasename': ' ',
    'maketitle': my_title
}

latex_documents = [
    (master_doc, 'gsl-kor-manual.tex', title, my_latex_authors, 'manual')
]

#latex_logo = 'logo_design.svg'


def setup(app):
        app.add_css_file('custom.css')
