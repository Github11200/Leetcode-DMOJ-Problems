graph = {}

graph["start"] = {}

graph["start"]["a"] = 6
graph["start"]["b"] = 2

graph["a"] = {}

graph["a"]["finish"] = 1

graph["b"] = {}

graph["b"]["a"] = 3
graph["b"]["finish"] = 5

graph["finish"] = {}

costs = {}
costs["a"] = 6
costs["b"] = 2
costs["finish"] = float("inf")

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["finish"] = None

processed = []


def find_cheapest_node(costs):
    least_cost = float("inf")
    cheapest_node = None
    for cost in costs:
        node_cost = costs[cost]
        if node_cost < least_cost and not cost in processed:
            cheapest_node = cost
            least_cost = node_cost
    return cheapest_node


def dijkstras_algorithm(graph):
    cheapest_node = find_cheapest_node(costs=costs)
    while cheapest_node:
        cost = costs[cheapest_node]
        neighbours = graph[cheapest_node]
        for neighbour in neighbours:
            new_cost = cost + neighbours[neighbour]
            if new_cost < costs[neighbour]:
                costs[neighbour] = new_cost
                parents[neighbour] = cheapest_node
        processed.append(cheapest_node)
        cheapest_node = find_cheapest_node(costs=costs)


dijkstras_algorithm(graph=graph)
print(costs["finish"])
