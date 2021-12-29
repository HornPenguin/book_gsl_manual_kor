from docutils.writers.latex2e import Babel

Babel.language_codes = {'ko':'korean', 'en':'english'}

# Configuration file for the Sphinx documentation builder.

# -- Project information

project = 'GNU 과학 계산 라이브러리'
copyright = '2021, Hyun Seong, Kim'
author = 'GSL Team'
translator = 'Hyun Seong, Kim'

release = '2.7.1'
version = '0.1.0'

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

intersphinx_mapping = {
    'python': ('https://docs.python.org/3/', None),
    'sphinx': ('https://www.sphinx-doc.org/en/master/', None),
}
intersphinx_disabled_domains = ['std']

templates_path = ['_templates']
static_path = ['_static']

numfig = True

# -- Options for HTML output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
html_logo = "_static/logo_design.svg"
html_theme_options = {
    'logo_only': True,
    'display_version': False,
}

# -- Options for EPUB output
epub_show_urls = 'footnote'
epub_author ='Hyun Seong, Kim'
epub_publisher = 'OFPublisher'


release = ' '

latex_engine = 'xelatex'

latex_elements = {
    'papersize': 'a4paper',
    'pointsize': '10pt',
    'preamble': r'''
    \usepackage{svg}
    \usepackage{afterpage}
    \usepackage[pagecolor=none]{pagecolor}
    \usepackage{tikz}
    \usepackage{tikzpagenodes}

    \definecolor{coverbackground}{RGB}{209, 198, 161}
    \definecolor{coverband}{RGB}{239, 190, 84}
    ''',
    'fontpkg': r'''
    \setmainfont{Noto Serif CJK KR}
    \setsansfont{Noto Sans CJK KR}
    \setmonofont{Noto Sans Mono CJK KR}
    ''',
    'releasename': ' ',
    'maketitle':r'''
    \newpage
    \pagecolor{coverbackground}\afterpage{\nopagecolor}
    \begin{tikzpicture}[remember picture,overlay,shift={(current page.north west)}]
    \fill[coverband,yshift=-120mm] rectangle(\paperwidth,85mm);
    \end{tikzpicture}
    \includegraphics[width=0.5\textwidth]{A Slick GNU Logo}
    \pagebreak

    \sphinxmaketitle
    '''
}

#latex_logo = '_static/logo_design.svg'


def setup(app):
        app.add_css_file('custom.css')
