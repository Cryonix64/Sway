#!/usr/bin/env python3
"""
Quick start guide for Sway Programming Language
Run this to see all examples compile and execute
"""

import subprocess
import os
import sys

def run_example(filename):
    """Run a single Sway example"""
    filepath = f"examples/{filename}"
    
    if not os.path.exists(filepath):
        print(f"❌ Not found: {filepath}")
        return False
    
    print(f"\n{'='*60}")
    print(f"📦 Running: {filename}")
    print(f"{'='*60}")
    
    try:
        result = subprocess.run(
            ['python3', 'sway.py', 'run', filepath],
            capture_output=True,
            text=True,
            timeout=5
        )
        
        if "error" in result.stderr.lower():
            print(f"❌ Error: {result.stderr}")
            return False
        else:
            print(f"✅ Success")
            return True
    
    except subprocess.TimeoutExpired:
        print(f"⏱️ Timeout")
        return False
    except Exception as e:
        print(f"❌ Exception: {e}")
        return False

def main():
    """Run all examples"""
    os.chdir('/home/dozirod/Documents/sway')
    
    examples = [
        'simple.sway',
        'arithmetic.sway',
        'conditions.sway',
        'factorial.sway',
        'fibonacci.sway',
        'loops.sway',
        'calculator.sway',
        'max.sway',
        'sum.sway',
    ]
    
    print("""
╔═══════════════════════════════════════════════════════════╗
║        🚀 Sway Programming Language Demo                  ║
║                                                           ║
║  Swift-inspired language that compiles to C              ║
╚═══════════════════════════════════════════════════════════╝
    """)
    
    print("📋 Examples to run:")
    for i, example in enumerate(examples, 1):
        print(f"   {i}. {example}")
    
    print("\n⏳ Running all examples...\n")
    
    results = {}
    for example in examples:
        results[example] = run_example(example)
    
    # Summary
    print(f"\n{'='*60}")
    print(" 📊 SUMMARY")
    print(f"{'='*60}")
    
    passed = sum(1 for v in results.values() if v)
    total = len(results)
    
    for example, success in results.items():
        status = "✅ PASS" if success else "❌ FAIL"
        print(f"{status:8} {example}")
    
    print(f"\n📈 Result: {passed}/{total} examples passed")
    
    if passed == total:
        print("\n🎉 All examples working perfectly!")
    else:
        print(f"\n⚠️  {total - passed} example(s) need attention")

if __name__ == '__main__':
    main()
