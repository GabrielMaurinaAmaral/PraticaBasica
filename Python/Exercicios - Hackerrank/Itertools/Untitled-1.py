def open_or_senior(data):
    cargos = [""]
    for d in data:
        if d[0] > 55 and d[1] > 7:
            cargos.append("Senior")
        else:
            cargos.append("Open")
    return cargos
