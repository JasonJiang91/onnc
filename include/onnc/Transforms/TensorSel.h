//===- TensorSel.h --------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_TRANSFORM_TENSOR_SELECTION_H
#define ONNC_TRANSFORM_TENSOR_SELECTION_H
#include <onnc/Core/ModulePass.h>
#include <onnc/Target/TargetBackend.h>
#include <onnc/Transforms/TensorSel/LowerRegistry.h>

namespace onnc {

/** \class TensorSel
 *  \brief TensorSel converts ONNX node to ComputeOperator and creates
 *  ComputeGraph objects for subgraph in ONNX.
 */
class TensorSel : public ModulePass
{
public:
  static char ID;

public:
  TensorSel(const TargetBackend* pBackend = nullptr);

  virtual ~TensorSel();

  Pass::ReturnType runOnModule(::onnc::Module &pModule) override;

  LowerRegistry& getLowerRegistry() { return m_LowerRegistry; }

  const LowerRegistry& getLowerRegistry() const { return m_LowerRegistry; }

  StringRef getPassName() const override { return "TensorSel"; }

protected:
  const TargetBackend* m_pBackend;
  LowerRegistry m_LowerRegistry;
};

ModulePass *CreateTensorSel(const TargetBackend* pBackend);

} // namespace of onnc

#endif