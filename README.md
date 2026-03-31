push_swap/ ├── Stack Operations (swap.c, rotate.c, reverse_rotate.c) ├── List Utilities (ft_lstclear.c, add_node.c) ├── Adaptive Sorting (tri_tree_elements.c, meduim.c, tri_more_than_tree.c) ├── Cost Calculation (cost.c, cost_rr.c, tab_rr.c) └── Bonus Checker (checker.c - validates solutions)

Code

### 🔍 Integrated Validation
A **bonus checker** program validates each solution and displays results in real-time.

## 🛠️ Installation & Compilation

```bash
# Clone the repository
git clone https://github.com/somaya-Hassoune/push_swap.git
cd push_swap

# Compile the main program
make

# Compile with bonus checker
make bonus

# Clean build artifacts
make clean && make fclean
📖 Usage
bash
# Run push_swap with a list of numbers
./push_swap 4 67 3 87 23

# Validate the solution with the checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

# Or with arguments as a single string
./push_swap "4 67 3 87 23" | ./checker "4 67 3 87 23"
Example Output
Code
pb
ra
pb
ra
pa
sa
pa
📊 Algorithm & Complexity
Size	Strategy	Max Operations
2-3 elements	Direct sort	2-3
4-5 elements	Positional	~5
100+ elements	Chunk-based	~600
500+ elements	Optimized chunks	~5500
Optimization Principles
Cost Calculation : Evaluates movement cost for each element
Greedy Selection : Always chooses the least expensive operation
Operation Fusion : Uses rr and rrr to combine rotations
Strategic Positioning : Places elements to minimize future movements
🎓 Demonstrated Concepts
✅ Data structures (linked lists, stacks)
✅ Greedy algorithms & optimization
✅ Memory management in C
✅ Argument parsing & validation
✅ Algorithmic complexity analysis
🧪 Testing
bash
# Test with 3 numbers (trivial solution)
./push_swap 3 2 1

# Test with 100 random numbers
./push_swap $(shuf -i 1-1000 -n 100 | tr '\n' ' ')

# Check number of operations
./push_swap 4 67 3 87 23 | wc -l
📝 Included Utilities
File	Function
ft_atoi.c	String to int conversion with validation
ft_split.c	Argument parsing into tokens
ft_strlen.c, ft_strncmp.c	Standard string utilities
ft_new_node.c, add_node.c	Linked list management
printf/ folder	Mini printf for debugging
get_next_line/ folder	Line-by-line reading (bonus checker)
🌟 Project Strengths
Efficient Algorithm : Optimized operation count
Maintainable Code : Clear function names and logic
Robust Error Handling : Strong input validation
Extensible Design : Easy to add new sorting strategies
🚧 Future Improvements
 Graphical visualizer for stack movements
 Benchmark comparison with other algorithms
 Support for very large inputs (memory optimization)
 Multi-threaded version
📄 License
This project is distributed under the MIT License.

Created by: somaya-Hassoune
Last Updated: 2026
