from docutils.writers.latex2e import Babel
from latex_setting import *

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

my_latex_authors = 'Mark Galassi \\\\ \
                    Jim Davies \\\\ \
                    James Theiler \\\\ \
                    Brian Gough \\\\ \
                    Gerard Jungman \\\\ \
                    Patrick Alken \\\\ \
                    Michael Booth \\\\ \
                    Fabrice Rossi \\\\ \
                    Rhys Ulerich \\\\~\\\\ \
                    저\\\\~\\\\ \
                    \\small{번역}:  김현성 \\\\'

my_preamble = r'''  
    {0}

    {1}                        
    '''.format(packages, custom_setting)

my_cover_and_license = r'''
    \newpage
    {0}

    \newpage

    {1}

    \newpage

    \sphinxmaketitle
    '''.format(cover_page,license_page)

latex_elements = {
    'papersize': 'a4papaer',
    'pointsize': '10pt',
    'preamble': my_preamble,
    'fontpkg' : r'''
    \setmainfont{Noto Serif CJK KR}
    \setsansfont{Noto Sans CJK KR}
    \setmonofont{Noto Sans Mono CJK KR}
    '''
}

'''
,
    "maketitle": my_cover_and_license

'''
latex_documents = [
    (master_doc, 
    'gsl-kor-manual.tex',
     title, 
     my_latex_authors, 
     'manual')
]

#latex_logo = 'logo_design.svg'
<<<<<<< HEAD
latex_show_urls = 'inline'
latex_use_xindy =True
=======
>>>>>>> parent of e26ce97 (Style setting for latex)
