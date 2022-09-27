#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	
	int V, E;
	cin >> V >> E;

	vector<pair<int, int>> edges(E);
	for (int i = 0; i < E; i++) {
		cin >> edges[i].first >> edges[i].second;
	}

	vector<int> color(V, 0);
	color[0] = 1;
	for (int i = 1; i < V; i++) {				
		std::set<int> colors;

		for (int j = 0; j < E; j++) {				
			if (edges[j].first == i) {				
				colors.insert(color[edges[j].second]);			
			}
			else if (edges[j].second == i) {		        
				colors.insert(color[edges[j].first]);		        
			}
		}
		
		for (int j = 1; j < V + 1; j++) {				
			auto search = colors.find(j);				
			if (search != colors.end()) {				
			}
			else {																	
				color[i] = j;						
				break;
			}
		}
	}
	
	for (int i = 0; i < V; i++)
	cout << color[i] << " ";

	sort(color.begin(), color.end());
	cout << endl;
	cout << *(color.end() - 1);
}