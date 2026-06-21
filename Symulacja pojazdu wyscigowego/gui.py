import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt
from fontTools.diff import color
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from physics import Bolid, Circuit


class SimApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Simulation of a racing car")
        self.root.geometry("900x600")

        self.circuit = Circuit()

        control_panel = tk.Frame(root, width=250, padx=10, pady=10)
        control_panel.pack(side=tk.LEFT, fill=tk.Y)

        tk.Label(control_panel, text="Car's parameters:", font=('Arial', 16, 'bold')).pack(anchor=tk.W, pady=6)
        self.entry_mass = self.create_input(control_panel, "Car's mass (kg):", "800")
        self.entry_force = self.create_input(control_panel, "Car's force (N):", "9000")
        self.entry_cd = self.create_input(control_panel, "Air resistance (Cd):", "0.9")
        self.entry_a = self.create_input(control_panel, "Surface (m^2):", "1.5")

        btn_calc = tk.Button(control_panel, text="START SIMULATION", command=self.start_sim, bg="#4CAF50", fg="white",
                             font=('Arial', 14, 'bold'))
        btn_calc.pack(fill=tk.X, pady=20)

        self.lbl_result = tk.Label(root, bg="white")
        self.lbl_result.pack(anchor=tk.NW, pady=10)

        tk.Label(control_panel, text="Frontal Area Visualization:", font=('Arial', 12, 'italic')).pack(anchor=tk.W,
                                                                                                      pady=(10, 2))
        self.surface_canvas = tk.Canvas(control_panel, width=120, height=120, bg="#E0E0E0", highlightthickness=1,
                                        highlightbackground="gray")
        self.surface_canvas.pack(anchor=tk.W, pady=5)
        self.draw_surface_square(1.5)

        self.charts_panel = tk.Frame(root, bg="white")
        self.charts_panel.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True)
        self.fig, (self.ax1, self.ax2) = plt.subplots(2, 1, figsize=(8, 4))
        self.canvas = FigureCanvasTkAgg(self.fig, master=self.charts_panel)
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)

        self.charts_refresh([], [], self.circuit.x_coords, self.circuit.y_coords)

    def draw_surface_square(self, area):

        self.surface_canvas.delete("all")

        if area <= 0:
            return

        import math

        max_canvas_side = 100
        max_area = 4.0

        side_px = max_canvas_side * (math.sqrt(area) / math.sqrt(max_area))
        side_px = min(side_px, max_canvas_side)

        offset = side_px / 2
        x0, y0 = 60 - offset, 60 - offset
        x1, y1 = 60 + offset, 60 + offset

        self.surface_canvas.create_rectangle(x0, y0, x1, y1, fill="#FFCDD2", outline="#B71C1C", width=2)
        self.surface_canvas.create_text(60, 60, text=f"{area} m²", font=('Arial', 9, 'bold'), fill="#B71C1C")

    def create_input(self, parent, text, default_val):
        frame = tk.Frame(parent)
        frame.pack(fill=tk.X, pady=10)
        lbl = tk.Label(frame, text=text, font=('Arial', 14))
        lbl.pack(side=tk.LEFT)
        entry = tk.Entry(frame, width=20, font=('Arial', 14))
        entry.insert(0, default_val)
        entry.pack(side=tk.RIGHT, padx=5)
        return entry

    def start_sim(self):
        try:
            m = float(self.entry_mass.get())
            f = float(self.entry_force.get())
            cd = float(self.entry_cd.get())
            a = float(self.entry_a.get())

            car = Bolid(mass=m, engine_force=f, Cd=cd, A=a)
            times, velocities = car.sim_straight(distance=100)
            lap_time = self.circuit.sim_lap_time(car)

            self.lbl_result.config(text=f"Lap time: {lap_time:.3f} s", fg="blue", width=20, font=('Arial', 14))
            self.charts_refresh(times, velocities, self.circuit.x_coords, self.circuit.y_coords)
            self.draw_surface_square(a)
        except ValueError:
            messagebox.showerror("Error!", "Please enter a proper value!")

    def charts_refresh(self, t, v, tx, ty):
        self.ax1.clear()
        self.ax2.clear()

        self.ax1.plot(t, v, color='red', linewidth=2)
        self.ax1.set_title("Acceleration on straight (100m)")
        self.ax1.set_xlabel("Time (s)")
        self.ax1.set_ylabel("Velocity (m/s)")
        self.ax1.grid(True)

        self.ax2.plot(tx, ty, color='blue', linestyle='--', marker='o')
        self.ax2.set_title("Test track geometry")
        self.ax2.set_xlabel("x (m)")
        self.ax2.set_ylabel("y (m)")
        self.ax2.axis("equal")
        self.ax2.grid(True)

        self.fig.tight_layout()
        self.canvas.draw()
