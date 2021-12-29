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
    'sphinx.ext.intersphinx'
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

numfig = True

# -- Options for HTML output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
html_logo = "_static/logo_design.gif"
html_theme_options = {
    'logo_only': True,
    'display_version': False,
}

# -- Options for EPUB output
epub_show_urls = 'footnote'
epub_author ='Hyun Seong, Kim'
epub_publisher = 'OFPublisher'


release = ''

latex_engine = 'xelatex'
latex_elements = {
    'pointsize': '9pt',
    'fontpkg': r'''
\setmainfont{Noto Serif CJK KR}
\setsansfont{Noto Sans CJK KR}
\setmonofont{Noto Sans Mono CJK KR}
    ''',
    'preamble': r'''
\usepackage{pdfpages}
\includepdf[pages=1]{_static/Cover.pdf}
    ''',
    'releasename': ''
}




def setup(app):
        app.add_css_file('custom.css')
