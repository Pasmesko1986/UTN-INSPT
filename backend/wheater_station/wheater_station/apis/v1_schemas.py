#!/usr/bin/env python

"""
The purpose of this module is to store all the `base-models` of the parameters 
used in the APIs for validation, likewise, it contains tools for managing them.
For more info of how to build `base-models`, see: https://pydantic-docs.helpmanual.io/usage/models/
"""

__author__ = "Hector Vergara"
__email__ = "hvergara@inovecode.com"
__version__ = "2.0"

from typing import Optional, Union, List
from pydantic import BaseModel
#----------------------------------Charts---------------------------------

class InsertChartData(BaseModel):
    """
    Params to insert a new Chart data to the list.
    """
    type : str
    data: dict = {"a":10}