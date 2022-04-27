import std/[
  math,
  strformat,
]

const
  WIDTH = 512
  HEIGHT = 512

proc stripes(u, v: float): tuple[r: float, g: float, b: float] =
  const N = 2
  return (
    (sin(u * N) + 1) / 2,
    (sin((u + v) * N) + 1) / 2,
    (cos(v * N) + 1) / 2,
  )

proc main =
  let f = open("output.ppm", fmWrite)
  defer: f.close()

  f.writeLine("P6")
  f.writeLine(fmt"{WIDTH} {HEIGHT} 255")
  for y in 0..<HEIGHT:
    for x in 0..<WIDTH:
      let u = x / WIDTH
      let v = y / HEIGHT
      let (r, g, b) = stripes(u, v)
      f.write(chr(int(r * 255)))
      f.write(chr(int(g * 255)))
      f.write(chr(int(b * 255)))

when isMainModule:
  main()
