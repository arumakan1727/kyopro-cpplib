template_base_file := ../include/template-parts/template.cpp
template_base_file_dir := $(dir ${template_base_file})
template_export_file := ./template.cpp
template_base_file_dependencies := $(addprefix ${template_base_file_dir}, $(shell grep -e '//\s*@\s*include' ${template_base_file} | sed -r 's|//\s*@\s*include\s*"(.+)"|\1|'))

.PHONY:	all debug

all:	${template_export_file}

debug:
	@echo "template_base_file: ${template_base_file}"
	@echo "template_base_file_dir: ${template_base_file_dir}"
	@echo "template_export_file: ${template_export_file}"
	@echo "template_base_file_dependencies: ${template_base_file_dependencies}"

${template_export_file}: ${template_base_file} ${template_base_file_dependencies}
	expand-include $< > $@
