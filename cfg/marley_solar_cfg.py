from __future__ import print_function

import argparse

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import AutoMinorLocator, MultipleLocator

# parse arguments from command
parser = argparse.ArgumentParser(description="Generate MARLEY configuration")
parser.add_argument("file", type=str, default=None, help="input flux file")
parser.add_argument("--plot", dest="plot", action="store_true")
parser.add_argument("--no-plot", dest="plot", action="store_false")

args = parser.parse_args()
input_file = args.file
plot = args.plot

# load values from file
X = np.loadtxt(input_file, skiprows=4)
x = X[:, 0] / 1e6    # energy [MeV]
y = X[:, 1]          # flux [eV^-1 cm^-2 s^-1]
dx = np.gradient(x)  # bin width

# template for MARLEY configuration file
cfg = """
// Use this example configuration file as a starting point for your own files.
{{
  seed: 123456, // Random number seed (omit to use time since Unix epoch)

  // Reaction matrix element files
  reactions: [ "ve40ArCC_Bhattacharya2009.react" ],

  // Neutrino source specification
  source: {{
    type: "histogram",
    neutrino: "ve",

    // Low edges of energy bins (MeV)
    E_bin_lefts: {},

    // Bin weights (dimensionless)
    weights: {},

    // Upper edge of the final bin (MeV)
    Emax: {},
  }},

  // Incident neutrino direction 3-vector
  direction: {{ x: 0.0, y: -1.0, z: 0.0 }},

}}"""

# print out the cofiguration
print(
    cfg.format(
        np.array2string(x, precision=2, separator=', ', prefix='    '),
        np.array2string(y, separator=', ', prefix='    '),
        (x[-1]+dx[-1]).round(2)
    )
)

if plot:

    # initialize figure
    fig = plt.figure(figsize=(7, 5))
    ax = fig.add_subplot(1, 1, 1)

    # plot the histogram
    ax.fill_between(x, y, color='C0')
    ax.step(x, y, where='post', color='C2', linewidth=3)

    # set labels
    ax.set_xlabel('energy [MeV]', horizontalalignment='right', x=1.0,
                  fontsize=14)
    ax.set_ylabel('flux [eV$^{-1}$ cm$^{-2}$ s$^{-1}$]',
                  horizontalalignment='right', y=1.0, fontsize=14)

    # configure tick properties
    ax.tick_params(axis='both', which='major', labelsize=14)
    ax.xaxis.set_minor_locator(AutoMinorLocator())
    ax.yaxis.set_minor_locator(AutoMinorLocator())

    # set grid lines
    ax.grid(True, which='both', axis='both', color='k', linestyle=':',
            linewidth=1, alpha=0.2)

    # set limit of axes
    ax.set_xlim(left=0)
    ax.set_ylim(bottom=0)

    # plot
    plt.tight_layout()
    plt.show()

