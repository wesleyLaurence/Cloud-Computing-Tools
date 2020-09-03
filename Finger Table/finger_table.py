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
