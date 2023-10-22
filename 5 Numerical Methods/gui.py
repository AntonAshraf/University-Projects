from tkinter import *
import tkinter as tk
from calculations import calculate_root, clear_results

# Define the function for changing the labels based on the selected method
def on_method_change(*args, method_var, a_label, b_label, b_entry):
    method = method_var.get()

    a_label.config(text="Lower Bound (a):" if method in [
                   "Bisection", "False Position"] else "Initial Approximation (x0):")
    if method in ["Bisection", "False Position"]:
        b_label.config(text="Upper Bound (b):")
        b_entry.config(state=tk.NORMAL)
    elif method == "Secant":
        b_label.config(text="Initial Approximation (x1):")
        b_entry.config(state=tk.NORMAL)
    else:
        b_label.config(text="")
        b_entry.config(state=tk.DISABLED)


def create_gui(root):

    root.title("Numerical Methods Calculator")
    root.geometry("700x360")

    # Create a grid layout
    root.grid()
    # Add an empty label to create space at the top of the grid
    top_space_label = Label(root, height=2)
    top_space_label.grid(row=0, column=0)

    # Method selection
    method_var = tk.StringVar(value="Bisection")
    method_label = Label(root, text="Select Method:")
    method_label.grid(row=1, column=1)
    methods = ["Bisection", "False Position", "Secant",
               "Newton-Raphson", "Simple Fixed-Point Iteration"]
    method_menu = tk.OptionMenu(root, method_var, *methods)
    method_menu.grid(row=1, column=2)

    spacer_label = Label(root, text="")
    spacer_label.grid(row=2, column=0, columnspan=4)

    # Expression input
    expression_label = Label(root, text="Enter f(x):")
    expression_label.grid(row=3, column=1)
    expression_entry = Entry(root, width=35)
    expression_entry.grid(row=3, column=2)
    expression_entry.insert(0, "-2.3x^2 + 3x + 12")

    spacer_label = Label(root, text="")
    spacer_label.grid(row=4, column=0, columnspan=4)

    # Parameters input
    a_label = Label(root, text="Lower Bound (a):", width=25)
    a_label.grid(row=5, column=0)
    a_entry = Entry(root)
    a_entry.grid(row=5, column=1)
    a_entry.insert(0, "1")

    b_label = Label(root, text="Upper Bound (b):")
    b_label.grid(row=5, column=2)
    b_entry = Entry(root)
    b_entry.grid(row=5, column=3)
    b_entry.insert(0, "5")

    spacer_label = Label(root, text="")
    spacer_label.grid(row=6, column=0, columnspan=4)

    tolerance_label = Label(root, text="Tolerance:")
    tolerance_label.grid(row=7, column=0)
    tolerance_entry = Entry(root)
    tolerance_entry.insert(0, "0.01")
    tolerance_entry.grid(row=7, column=1)

    max_iterations_label = Label(root, text="Max Iterations:")
    max_iterations_label.grid(row=7, column=2)
    max_iterations_entry = Entry(root)
    max_iterations_entry.insert(0, "10")
    max_iterations_entry.grid(row=7, column=3)

    method_var.trace("w", lambda *args: on_method_change(method_var=method_var,
                     a_label=a_label, b_label=b_label, b_entry=b_entry))

    spacer_label = Label(root, text="")
    spacer_label.grid(row=8, column=0, columnspan=4)

    # Calculate button
    calculate_button = Button(root, text="Calculate", command=lambda: [clear_results(result_label, error_label, info_label), calculate_root(
        root, method_var, expression_entry, tolerance_entry, max_iterations_entry, a_entry, b_entry, result_label, error_label, info_label, check_var)])
    calculate_button.grid(row=9, column=1, columnspan=2)

    spacer_label = Label(root, text="")
    spacer_label.grid(row=10, column=0, columnspan=4)

    # Result labels
    result_label = Label(root, text="")
    result_label.grid(row=11, column=1, columnspan=2)
    error_label = Label(root, text="")
    error_label.grid(row=12, column=1, columnspan=2)
    info_label = Label(
        root, text="Note: The result is rounded to 6 decimal places.")
    info_label.grid(row=13, column=1, columnspan=2)

    # Checkbox for displaying the steps of iteration
    check_var = tk.IntVar(value=1)
    check_button = Checkbutton(
        root, text="Show Steps of Iteration", variable=check_var)
    check_button.grid(row=15, column=3)

    root.mainloop()
