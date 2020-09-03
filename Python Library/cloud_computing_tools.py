""" Algorithms for distributed systems and cloud computing. """

import numpy as np
import pandas as pd

class BloomFilter:
    
    def __init__(self, m, elements):
        self.m = m
        self.elements = elements
        self.final = pd.Series(int)
        
    # define hash functions
    def h1(self, x):
        return ((x**2 + x**3)* 1) % self.m

    def h2(self, x):
        return ((x**2 + x**3)* 2) % self.m

    def h3(self, x):
        return ((x**2 + x**3)* 3) % self.m
    
    def array(self):
        
        # create array
        array = np.zeros(self.m)
        
        # run each hash function
        for x in self.elements:
            array[self.h1(x)] = 1
            array[self.h2(x)] = 1
            array[self.h3(x)] = 1
        
        self.final = pd.Series(array.astype(int))
        
        return self.final
    
    def search(self, value):
        val1 = self.final[self.h1(value)]
        val2 = self.final[self.h2(value)]
        val3 = self.final[self.h3(value)]
        
        hash_vals = [val1,val2,val3]
        
        if 0 in hash_vals:
            status = "No value found"
        else:
            if value in self.elements: 
                status = "Value found"
            else:
                status = "False positive"    
        
        return status


class FingerTable:
    
    def create_table(n, m, nodes):

        # sort nodes in ascending order
        nodes.sort()

        # container
        values = []
        ft_list = []

        # helper function
        def finger(n, i, m):
            return (n + 2**i)%(2**m)

        # for each i, calculate finger table values
        for i in range(m):
            values.append(finger(n, i, m))

        for value in values:
            if value > nodes[-1]:
                ft = nodes[0]
            else:
                i=0
                for node in nodes[:-1]:
                    if value > node:
                        ft = nodes[i + 1]
                    i+=1

            ft_list.append(ft)

        return ft_list
    
        
class MTTF:
    
    def calculate(rate_of_failure, num_servers):
        """
        rate_of_failure: total years until failure
        num_servers: number of servers in datacenter

        RETURNS: MTTF (in hours)
        """
        months_until_failure = 12 * rate_of_failure
        hours_in_month = 24*30

        return (months_until_failure*hours_in_month) / num_servers
       
    
class PUE:
    
    def calculate(total_power, IT_power):
        return total_power / IT_power
