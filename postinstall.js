#!/usr/bin/env node

const fs = require('fs')

let arch = process.arch
let platform = process.platform
let platformStr = ''

if (arch === 'ia32') {
  arch = 'x86'
}

if (platform === 'win32') {
  platformStr = 'win'
} else {
  platformStr = platform
}

const filename = 'bin/graphql-to-reason-' + platformStr + '-' + arch + '.exe'
const supported = fs.existsSync(filename)
console.info('added binary:', filename)
if (supported) {
  fs.chmodSync(filename, 755)
  console.info('added binary:', filename)
} else {
  console.info('not,supported, didnt add binary:', filename)
}
