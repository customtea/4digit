def operant(ope, x, y)
  case ope
  when 0
    return (x + y)
  when 1
    return (x - y)
  when 2
    return (x * y)
  when 3
    return (x / y)
  end

end

def print_operant(ope)
  case ope
  when 0
    print "+"
  when 1
    print "-"
  when 2
    print "x"
  when 3
    print "/"
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
  tmpfrac1 = operant(o1, frac[0], frac[1])
  tmpfrac2 = operant(o2, tmpfrac1, frac[2])
  tmpfrac3 = operant(o3, tmpfrac2, frac[3])
  return 1000 if tmpfrac3.denominator == 0
  tmpint = tmpfrac3.to_f
  
  if tmpint == 10
    print "((#{frac[0].numerator}#{r_ope(o1)}#{frac[1].numerator})#{r_ope(o2)}#{frac[2].numerator})#{r_ope(o3)}#{frac[3].numerator}\n"
    
    nume = Array.new(4)
    nume = frac.map{|num| num.numerator}

    #print frac[0].numerator
    #print_operant(o1)
    #print frac[1].numerator
    #print_operant(o2)
    #print frac[2].numerator
    #print_operant(o3)
    #print frac[3].numerator
    #print "\n"
  end

end

def ope_parm(frac)
  4.times do |o1|
    4.times do |o2|
      4.times do |o3|
        calc1(frac, o1, o2, o3)
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
