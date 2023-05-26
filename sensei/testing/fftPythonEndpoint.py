"""
PYTHON ANAYLSIS ENDPOINT

Simple endpoint for python based computations in the Sensei-FFT pipeline.
This script will be invoked by sensei pythonAnalysis adaptor and display different
visualizations for data computed by FFTW endpoint.

# Project: 
Sensei - FFTW - SFSU

# Contributions:
S. Kulkarni, E. Wes Bethel, B. Loring
2023
"""

import sys
import svtk.numpy_support as svtknp
from matplotlib import pyplot as plt

# Defaults:
mesh = "mesh"
array = "data"
out_file = 'python_output.png'

def Initialize():
  """ Initialization code """
  
  return

def Execute(dataAdaptor):
  """ Use sensei::DataAdaptor instance passed in
      dataAdaptor to access and process simulation data """
  
  sys.stderr.write("\n:: PYTHON ENDPOINT ::\n")
  sys.stderr.write(f"\n{sys.path}\n")

  my_rank = comm.Get_rank()

  dobj = dataAdaptor.GetMesh(mesh, False)
  point_data = dobj.GetPointData()
  data = point_data.GetArray(array)  
  data_np: numpy.ndarray = svtknp.svtk_to_numpy(data).flatten()

  local_n0_start, local_n0 = data_np[0], data_np[1]
  data_np = data_np[2:].reshape(int(local_n0), 12)

  sys.stderr.write(f"DEBUG log on rank {my_rank}:\n {data_np}\n{type(data_np)}\t{data_np.size}, {data_np.shape}\n")
  

  # # display the content
  plt.figure()
  plt.imshow(data_np, cmap='OrRd', origin='lower', alpha=1, aspect='auto')
  plt.colorbar()
  plt.title("FFTW")
  plt.savefig("fftw.png")

  return

def Finalize():
  """ Finalization code """
  # YOUR CODE HERE
  return
