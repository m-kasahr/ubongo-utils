#! /usr/bin/ruby
#                                                             -*- Ruby -*-
# Copyright (c) 2009  Motoyuki Kasahara
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the project nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

if ARGV.length < 2
  abort("#{$0}: too few argument.")
elsif ARGV.length > 2
  abort("#{$0}: too many arguments.")
end

$name = ARGV[0]
$data_path = ARGV[1]
$pieces = {}

$flip_flag = true
if (file = File.open("#{$data_path}/piece-flip-flag") rescue nil) != nil
  data = file.read
  file.close
  if data != nil && data.chomp == "false"
    $flip_flag = false
  end
end

$piece_count = 0
('A'..'Z').each do |id|
  file = "#{$data_path}/#{id}.piece"
  if FileTest.file?(file)
    next if (file = File.open(file) rescue nil) == nil
    data = file.read.gsub("\n", "\\n")
    $pieces[id] = data
    file.close
    $piece_count += 1
  end
end

print "#ifndef UBONGO_PIECESET_#{$name.upcase}_H\n"
print "#define UBONGO_PIECESET_#{$name.upcase}_H\n"
print "\n"
print "#include \"ubongo/pieceset.h\"\n"
print "\n"
print "namespace Ubongo {\n"
print "    class PieceSet_#{$name} : public PieceSet {\n"
print "    public:\n"
print "        PieceSet_#{$name}()\n"
print "            : PieceSet() {\n"
print "            static const Piece pieces[] = {\n"

('A'..'Z').each do |id|
  next if !$pieces.key?(id)
  print "                Piece(\"#{$pieces[id]}\"),\n"
end

print "            };\n"
print "            set_components(pieces, #{$piece_count}, #{$flip_flag});\n"
print "        }\n"
print "    };\n"
print "}\n"
print "\n"
print "#endif // UBONGO_PIECESET_#{$name.upcase}_HPP\n"
