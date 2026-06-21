import math



class Bolid:
    def __init__(self, mass=800, engine_force=9000, Cd=0.9, A=1.5, rho=1.1225):
        self.mass = mass #masa auta
        self.engine_force = engine_force #moc silnika
        self.Cd = Cd #opor powietrza
        self.A = A #pole powierchni auta od przodu
        self.rho = rho #gestosc powietrza

    def sim_straight(self, distance=100, dt=0.1): #dt to pochodna z czasu
        velocity = 0.0
        position = 0.0
        time = 0.0

        times = [time]
        velocities = [velocity]


        while position < distance:
            drag = 0.5 * self.rho * self.Cd * self.A * (velocity ** 2) #opor
            force = self.engine_force - drag
            acceleration = force / self.mass

            velocity += acceleration * dt
            position += velocity * dt
            time += dt

            times.append(time)
            velocities.append(velocity)

            if time > 20:
                break
        return times, velocities

    def max_velocity_in_turn(self, radius, mu=1.6, g=9.81): #mu to wspolczynnik tarcia
        if radius is None:
            return 70.0
        return math.sqrt(mu * g * radius)


class Circuit:
    def __init__(self):

        self.segments = [
            {"length": 100, "radius": None},
            {"length": 141, "radius": 120},
            {"length": 100, "radius": None},
            {"length": 100, "radius": 40},
            {"length": 141, "radius": 80},
            {"length": 100, "radius": None},
            {"length": 141, "radius": 80},
            {"length": 200, "radius": 90}
        ]

        self.x_coords = [0, 100, 200, 300, 300, 200, 100, 0, 0]
        self.y_coords = [0, 0, 100, 100, 200, 300, 300, 200, 0]

    def sim_lap_time(self, car, mu=1.6):
        total_time = 0.0
        for segment in self.segments:
            if segment["radius"] is None:
                times, velocities = car.sim_straight(distance=segment["length"])
                if times:
                    total_time += times[-1]
            else:
                v = car.max_velocity_in_turn(segment["radius"], mu)
                time_in_segment = segment["length"] / v
                total_time += time_in_segment
        return total_time
