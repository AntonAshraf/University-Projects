import matplotlib.pyplot as plt
import numpy as np
import matplotlib.backends.backend_tkagg
plt.switch_backend("TkAgg")

def plot_secant_method(f, x0, x1, max_iterations, tolerance):
    # Generate x values for plotting the function
    x = np.linspace(x0 - 10, x1 + 10, 100)
    y = np.array([f(xi) for xi in x])


    # Create a figure and axes for the plot
    fig, ax = plt.subplots(figsize=(10, 6))

    # Plot the function
    ax.plot(x, y, label='F(x)')

    # Initialize the iteration counter
    iteration = 0

    # Perform the Secant method iterations
    while iteration < max_iterations:
        # Calculate the function values at the endpoints
        f0 = f(x0)
        f1 = f(x1)

        # Calculate the new estimate
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0)

        # Clear the current plot
        ax.clear()

        # Plot the function
        ax.plot(x, y, label='f(x)')

        # Plot the estimate with a different color for each iteration
        color = plt.cm.viridis(iteration / max_iterations)
        ax.plot(x2, f(x2), 'o', color=color, label=f'Iteration {iteration+1}')

        # Plot vertical lines for x0 and x1
        ax.axvline(x0, color='red', linestyle='--', label='x0')
        ax.axvline(x1, color='blue', linestyle='--', label='x1')

        # Add labels and legend to the plot
        ax.set_xlabel('x')
        ax.set_ylabel('f(x)')
        ax.legend()

        # Add a title and annotation for the root
        ax.set_title('Secant Method')
        ax.annotate(f'Root: x = {x2:.4f}', xy=(x2, f(x2)), xytext=(x2, f(x2) + 0.5),
                    arrowprops=dict(facecolor='black', arrowstyle='->'))

        # Show the x and y axes
        ax.axhline(0, color='black', linewidth=0.5)
        ax.axvline(0, color='black', linewidth=0.5)

        # Draw the plot
        plt.draw()
        plt.pause(1)  # Delay for 1 second

        # Check if the root is found
        if abs(x2 - x1) < tolerance:
            break

        # Update the estimates
        x0 = x1
        x1 = x2

        # Increment the iteration counter
        iteration += 1

    # Show the final plot
    plt.show()
    
if __name__ == '__main__':
    # Define the function
    def f(x):
        return x**3 - 2*x**2 - 5

    # Define the derivative of the function
    def f_prime(x):
        return 3*x**2 - 4*x

    # Plot the function
    plot_secant_method(f, 3, 4, 10, 0.0001)