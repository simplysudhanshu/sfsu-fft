# -*- coding: utf-8 -*-
#
# Configuration file for the Sphinx documentation builder.
#
# This file does only contain a selection of the most common options. For a
# full list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path and environment setup ----------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys
# sys.path.insert(0, os.path.abspath('.'))

readTheDocs = os.environ.get('READTHEDOCS', None) != None
localReadTheDocs = os.environ.get('LOCALREADTHEDOCS', None) != None
localSkipDoxygen = os.environ.get('LOCALSKIPDOXYGEN', None) != None
sourcedir = sys.argv[-2]
builddir = sys.argv[-1]

# -- Project information -----------------------------------------------------

project = u'SENSEI'
copyright = u'2018, Lawrence Berkeley Lab, Oak Ridge Lab, Argonne Lab, Intelligent Light, Kitware'
author = u'Lawrence Berkeley Lab, Oak Ridge Lab, Argonne Lab, Intelligent Light, Kitware'

# The short X.Y version
version = u'2.2'
# The full version, including alpha/beta/rc tags
release = u'2.2.1'


# -- General configuration ---------------------------------------------------

# If your documentation needs a minimal Sphinx version, state it here.
#
# needs_sphinx = '1.0'

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinxcontrib.doxylink', 'sphinx.ext.mathjax'
]

numfig = True

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# The suffix(es) of source filenames.
# You can specify multiple suffix as a list of string:
#
# source_suffix = ['.rst', '.md']
source_suffix = '.rst'

# The master toctree document.
master_doc = 'index'

# The language for content autogenerated by Sphinx. Refer to documentation
# for a list of supported languages.
#
# This is also used if you do content translation via gettext catalogs.
# Usually you set "language" from the command line for these cases.
language = None

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path .
exclude_patterns = [u'_build', 'Thumbs.db', '.DS_Store']

# The name of the Pygments (syntax highlighting) style to use.
pygments_style = 'sphinx'


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

# Theme options are theme-specific and customize the look and feel of a theme
# further.  For a list of options available for each theme, see the
# documentation.
#
# html_theme_options = {}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

# Custom sidebar templates, must be a dictionary that maps document names
# to template names.
#
# The default sidebars (for documents that don't match any pattern) are
# defined by theme itself.  Builtin themes are using these templates by
# default: ``['localtoc.html', 'relations.html', 'sourcelink.html',
# 'searchbox.html']``.
#
html_sidebars = {'**':['globaltoc.html', 'relations.html', 'sourcelink.html', 'searchbox.html']}
#


# -- Options for HTMLHelp output ---------------------------------------------

# Output file base name for HTML help builder.
htmlhelp_basename = 'SENSEIdoc'


# -- Options for LaTeX output ------------------------------------------------

latex_elements = {
    # The paper size ('letterpaper' or 'a4paper').
    #
    # 'papersize': 'letterpaper',

    # The font size ('10pt', '11pt' or '12pt').
    #
    # 'pointsize': '10pt',

    # Additional stuff for the LaTeX preamble.
    #
    # 'preamble': '',

    # Latex figure (float) alignment
    #
    # 'figure_align': 'htbp',
}

# Grouping the document tree into LaTeX files. List of tuples
# (source start file, target name, title,
#  author, documentclass [howto, manual, or own class]).
latex_documents = [
    (master_doc, 'SENSEI.tex', u'SENSEI Documentation',
     u'Lawrence Berkeley Lab, Oak Ridge Lab, Argonne Lab, Intelligent Light, Kitware', 'manual'),
]


# -- Options for manual page output ------------------------------------------

# One entry per manual page. List of tuples
# (source start file, name, description, authors, manual section).
man_pages = [
    (master_doc, 'sensei', u'SENSEI Documentation',
     [author], 1)
]


# -- Options for Texinfo output ----------------------------------------------

# Grouping the document tree into Texinfo files. List of tuples
# (source start file, target name, title, author,
#  dir menu entry, description, category)
texinfo_documents = [
    (master_doc, 'SENSEI', u'SENSEI Documentation',
     author, 'SENSEI', 'One line description of project.',
     'Miscellaneous'),
]

# -- Doxylink configuration -----------------------------------------------

# The doxylink environment is set up with a dictionary mapping
# the interpereted text role to a tuple of tag file and prefix:
tagbase = os.path.join(builddir, 'rtd-docs', 'reference')
refbase = os.path.join('rtd-docs', 'reference')
if readTheDocs or localReadTheDocs:
    # We store the reference documentation inside the user-doc build
    # directory on readthedocs so that it will get installed properly.
    tagbase = os.path.abspath(os.path.join(builddir, 'rtd-docs', 'reference'))
    refbase = os.path.join('rtd-docs', 'reference')
#print('tagbase %s refbase %s' % (tagbase, refbase))
doxylink = {
    'sensei': (
        os.path.join(tagbase, 'sensei.tags'),
        os.path.join(refbase, 'sensei', 'html'))
}

# A boolean that decides whether parentheses are appended to
# function and method role text. Default is True.
# add_function_parentheses = True

# -- Run doxygen on sensei for doxylinks -------------------------------------

def runDoxygen(rtdsrcdir, rtdblddir, doxyfileIn, doxyfileOut):
    """Run Doxygen as part of generating user documentation.

    This is only meant to be used on readthedocs.org to generate
    reference documentation for linking into the user's guide and
    tutorial. It could eventually be replaced by something that
    fetches tag files, XML files, and references remotely-generated
    documentation from an full build of sensei.
    """
    import re
    import subprocess
    dxiname = open(os.path.join(rtdsrcdir, doxyfileIn), 'r')
    cfg = dxiname.read()
    orgdir = os.path.abspath(os.getcwd())
    srcdir = os.path.abspath(os.path.join(os.getcwd(), '..'))
    bindir = srcdir
    refdir = os.path.abspath(os.path.join(rtdblddir, 'rtd-docs', 'reference'))
    cfg2 = re.sub('@sensei_SOURCE_DIR@', srcdir,
        re.sub('@sensei_BINARY_DIR@', os.path.abspath(rtdblddir),
            re.sub('@sensei_VERSION@', release, cfg)))
    try:
        os.makedirs(refdir)
    except OSError as e:
        if e.errno == 17:
            pass
    except:
        print('Failed to create doxygen reference directory %s' % refdir)
        return
    dxoname = os.path.abspath(os.path.join(refdir, doxyfileOut))
    dxo = open(dxoname, 'w')
    print(cfg2, file=dxo)
    dxo.close()
    os.chdir(refdir)
    print('Running Doxygen on %s' % dxoname)
    rcode = subprocess.call(('doxygen', dxoname))
    print('   Doxygen returned %s' % rcode)
    os.chdir(orgdir)

if readTheDocs or localReadTheDocs:
    """Configure files and run Doxygen ourselves"""
    # Run doxygen ourselves on ReadTheDocs.org so that doxylinks will work.
    if not localSkipDoxygen:
        runDoxygen(sourcedir, builddir, 'sensei.doxyfile.in', 'sensei.doxyfile')
