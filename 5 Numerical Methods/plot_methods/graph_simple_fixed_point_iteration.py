import matplotlib.pyplot as plt
import numpy as np
import matplotlib.backends.backend_tkagg
plt.switch_backend("TkAgg")

def plot_simple_fixed_point_iteration(g, x0, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(x0 - 10, x0 + 10, 100)
    y = np.array([f(xi) for xi in x])


    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the function
    ax.plot(x, y, label='g(x)')

    # Initialize the iteration counter
    iteration = 0

    # Perform the Fixed-Point method iterations
    while iteration < max_iterations:
        # Calculate the new estimate
        x1 = g(x0)

        # Clear the current plot
        ax.clear()

        # Plot the function
        ax.plot(x, y, label='G(x)')

        # Plot the estimate with a different color for each iteration
        color = plt.cm.viridis(iteration / max_iterations)
        ax.plot(x1, g(x1), 'o', color=color, label=f'Iteration {iteration+1}')

        # Plot vertical line for the estimated root
        ax.axvline(x1, color='red', linestyle='--', label='Estimated Root')

        # Add labels and legend to the plot
        ax.set_xlabel('x')
        ax.set_ylabel('g(x)')
        ax.legend()

        # Add a title and annotation for the root
        ax.set_title('Fixed-Point Method')
        ax.annotate(f'Root: x = {x1:.4f}', xy=(x1, g(x1)), xytext=(x1, g(x1) + 0.5),
                    arrowprops=dict(facecolor='black', arrowstyle='->'))

        # Show the x and y axes
        ax.axhline(0, color='black', linewidth=0.5)
        ax.axvline(0, color='black', linewidth=0.5)

        # Draw the plot
        plt.draw()
        # plt.pause(1)  # Delay for 1 second

        # Check if the root is found
        if abs(x1 - x0) < tolerance:
            break

        # Update the estimate
        x0 = x1

        # Increment the iteration counter
        iteration += 1

    # Show the final plot
    plt.show()
    
if __name__ == '__main__':
    # Define the function
    f = lambda x: x**3 + 4*x**2 - 10
    g = lambda x: (10 - x**3)**0.5 / 2
    # (10 - x^3)^0.5 /2
    # Set the initial guess
    x0 = 1

    # Set the maximum number of iterations
    max_iterations = 100

    # Set the tolerance
    tolerance = 1e-4

    # Plot the function and the iterations
    plot_simple_fixed_point_iteration(g, x0, max_iterations, tolerance)