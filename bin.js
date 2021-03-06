#!/usr/bin/env node
'use strict'

const child_process = require('child_process')
const path = require('path')
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

const filename = 'graphql-to-reason-' + platformStr + '-' + arch + '.exe'
let exe = path.join(__dirname, 'bin', filename)
let supported = fs.existsSync(exe)

if (!supported) {
  exe = path.join(
    __dirname,
    '_build',
    'install',
    'default',
    'bin',
    'graphql_to_reason.exe'
  )
  supported = fs.existsSync(exe)
}
if (!supported) {
  console.error('graphql-to-reason does not support this platform :(')
  console.error('')
  console.error(
    'graphql-to-reason comes prepacked as built binaries to avoid large'
  )
  console.error('dependencies at build-time.')
  console.error('')
  console.error(
    'If you want graphql-to-reason to support this platform natively,'
  )
  console.error('please open an issue at our repository, linked above. Please')
  console.error('specify that you are on the ' + platformStr + ' platform,')
  console.error('on the ' + arch + ' architecture.')
}

const delegate_args = process.argv.slice(2)

try {
  child_process.execFileSync(exe, delegate_args, { stdio: 'inherit' })
} catch (e) {
  console.error(
    'Error happened when running command',
    exe,
    'with args',
    delegate_args
  )
  console.error('')
  console.error(e)
  console.error('')
  process.exit(2)
}
