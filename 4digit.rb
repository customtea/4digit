def operant(ope, x, y)
  case ope
  when 0
    return (x + y)
  when 1
    return (x - y)
  when 2
    return (x * y)
  when 3
    return 1000 if y == 0

    return (x / y)
  end

end

def r_ope(ope)
  case ope
  when 0
    return "+"
  when 1
    return "-"
  when 2
    return "x"
  when 3
    return "/"
  end
end

def calc1(frac, o1, o2, o3)
  tmpfrac = operant(o3,operant(o2,operant(o1, frac[0], frac[1]), frac[2]), frac[3])
  return 1000 if tmpfrac.denominator == 0
  tmpint = tmpfrac.to_f
  if tmpint == 10
    print "((#{frac[0].numerator}#{r_ope(o1)}#{frac[1].numerator})#{r_ope(o2)}#{frac[2].numerator})#{r_ope(o3)}#{frac[3].numerator}\n"
  end
end

def calc2(frac, o1, o2, o3)
  tmpfrac = operant(o3,operant(o2,frac[2], operant(o1, frac[0], frac[1])), frac[3])
  return 1000 if tmpfrac.denominator == 0
  tmpint = tmpfrac.to_f
  if tmpint == 10
    print "(#{frac[2].numerator}#{r_ope(o2)}(#{frac[0].numerator}#{r_ope(o1)}#{frac[1].numerator}))#{r_ope(o3)}#{frac[3].numerator}\n"
  end
end

def calc3(frac, o1, o2, o3)
  tmpfrac = operant(o3, frac[3], operant(o2, frac[2], operant(o1, frac[0], frac[1])))
  return 1000 if tmpfrac.denominator == 0
  tmpint = tmpfrac.to_f
  if tmpint == 10
    print "#{frac[3].numerator}#{r_ope(o3)}(#{frac[2].numerator}#{r_ope(o2)}(#{frac[0].numerator}#{r_ope(o1)}#{frac[1].numerator}))\n"
  end
end

def calc4(frac, o1, o2, o3)
  tmpfrac = operant(o3, operant(o1, frac[0], frac[1]) ,operant(o2, frac[2], frac[3]))
  return 1000 if tmpfrac.denominator == 0 
  tmpint = tmpfrac.to_f
  if tmpint == 10
    print "(#{frac[0].numerator}#{r_ope(o1)}#{frac[1].numerator})#{r_ope(o3)}(#{frac[2].numerator}#{r_ope(o2)}#{frac[3].numerator})\n"
  end
end

def ope_parm(frac)
  4.times do |o1|
    4.times do |o2|
      4.times do |o3|
        calc1(frac, o1, o2, o3)
        calc2(frac, o1, o2, o3)
        calc3(frac, o1, o2, o3)
        calc4(frac, o1, o2, o3)
      end
    end
  end
end

def num_parm(numbers)
  frac = Array.new(4)
  4.times do |n1|
    4.times do |n2|
      if n2 != n1
        4.times do |n3|
          if n3 != n1 && n3 != n2
            4.times do |n4|
              if n4 != n1 && n4 != n2 && n4 != n3
                frac[0] = Rational(numbers[n1], 1)
                frac[1] = Rational(numbers[n2], 1)
                frac[2] = Rational(numbers[n3], 1)
                frac[3] = Rational(numbers[n4], 1)

                ope_parm(frac)
              end
            end
          end
        end
      end
    end
  end
end

def main
  print "Input 4 Numbers \'1234\'\n"

  digits = gets()

  if digits.chomp.length != 4
    print "Wrong. Please 4 numbers"
    exit
  end
  numbers = digits.chomp.split("").map!(&:to_i)

  num_parm(numbers)
end

if __FILE__ == $0
  main
end
